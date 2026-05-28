#include <Arduino.h>
#include <ETH.h>
#include <HTTPClient.h>

#include <font.h>
#include <base64.h>
#include <Grid.h>

#define ETH_ADDR        1
#define ETH_POWER_PIN   -1
#define ETH_MDC_PIN     23
#define ETH_MDIO_PIN    18
#define ETH_TYPE        ETH_PHY_LAN8720
#undef ETH_CLK_MODE
#define ETH_CLK_MODE    ETH_CLOCK_GPIO0_OUT

IPAddress local_IP(192, 168, 0, 43);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

constexpr size_t XML_BUFFER_SIZE = 2048;
static char currentContent[XML_BUFFER_SIZE];
static char lastContent[XML_BUFFER_SIZE];

bool eth_connected = false;

const char* layoutPayload = R"(<?xml version="1.0" encoding="UTF-8"?>
<MatrixDisplayService.RetrieveLayoutResponse>
  <LayoutData>
    <TimeStamp><Value>2024-06-01T12:00:00Z</Value></TimeStamp>
    <Layout>
      <LayoutField>
        <X><Value>0</Value></X>
        <Y><Value>0</Value></Y>
        <Width><Value>48</Value></Width>
        <Height><Value>26</Value></Height>
        <ContentRef><Value>5</Value></ContentRef>
      </LayoutField>
    </Layout>
  </LayoutData>
</MatrixDisplayService.RetrieveLayoutResponse>)";

bool createContentXml(
    const char* base64Image,
    char* outBuffer,
    size_t outBufferSize)
{
    int written = snprintf(
        outBuffer,
        outBufferSize,

        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<MatrixDisplayService.RetrieveContentResponse>"
        "<ContentData>"
        "<TimeStamp><Value>1970-01-02T00:04:50.0</Value></TimeStamp>"
        "<ContentRef><Value>5</Value></ContentRef>"
        "<Content>"
        "<ContentType>image/bmp</ContentType>"
        "<Data>%s</Data>"
        "</Content>"
        "</ContentData>"
        "</MatrixDisplayService.RetrieveContentResponse>",

        base64Image
    );

    // Buffer zu klein oder Fehler
    if (written < 0 || written >= (int)outBufferSize) {
        Serial.println("ERROR: XML Buffer zu klein");
        return false;
    }

    return true;
}

void postXml(const char* url, const char* payload) {

    HTTPClient http;

    Serial.print("POST ");
    Serial.print(url);
    Serial.print(" ... ");

    http.begin(url);

    http.addHeader("Content-Type", "application/xml");
    http.addHeader("Connection", "close");

    http.setTimeout(30000);
    http.setConnectTimeout(30000);

    int httpCode = http.POST((uint8_t*)payload, strlen(payload));

    if (httpCode == 200) {
        String response = http.getString();
    }
    else {
        Serial.print("POST failed: ");
        Serial.println(http.errorToString(httpCode));
    }

    http.end();

    delay(100); // avoid overload and give some time to clean up
    Serial.println("done!");
}

void postContent(const char* base64Image) {
  if (!createContentXml(
            base64Image,
            currentContent,
            sizeof(currentContent))) {
        return;
  }

  if (strcmp(currentContent, lastContent) == 0) {
        // same content
        return;
  }

  postXml("http://192.168.0.11:8080/RetrieveContent", currentContent);

  memcpy(
        lastContent,
        currentContent,
        strlen(currentContent) + 1);
}

void WiFiEvent(WiFiEvent_t event)
{
    switch (event)
    {
        case ARDUINO_EVENT_ETH_START:
          Serial.println("ETH Started");
          ETH.setHostname("wt32");
          break;

        case ARDUINO_EVENT_ETH_GOT_IP:
          Serial.print("ETH IP: ");
          Serial.println(ETH.localIP());
          eth_connected = true;
          break;

        case ARDUINO_EVENT_ETH_DISCONNECTED:
          Serial.println("ETH disconnected");
          eth_connected = false;
          break;

        default:
          Serial.print("Unknown ETH event: ");
          Serial.print(event);
          break;
    }
}

uint8_t buffer[512];
Grid<48,26> grid;

void displayGrid() {
    uint32_t bmpSize = grid.toBMP(buffer);

    char base64Buffer[500];
    size_t base64Len = base64::encode(buffer, bmpSize, base64Buffer);

    base64Buffer[base64Len] = '\0';

    postContent(base64Buffer);
}

void displayTextInMiddle(const char* text) {
    Serial.print("Display: ");
    Serial.println(text);

    int nrChars = strlen(text);

    int widthChar = 5;
    int heightChar = 7;
    int spaceBetweenChars = 1;

    int widthText = (nrChars * widthChar) + ((nrChars - 1) * spaceBetweenChars);
    int heightText = heightChar;

    int xText = (48 - widthText) / 2;
    int yText = (26 - heightText) / 2;

    grid.clear();

    for (size_t i = 0; i < nrChars; i++) {
        char c = text[i];
        const Bitmap* bitmap = getBitmap(c);
        grid.addBitmap(xText, yText, bitmap);

        xText += widthChar + spaceBetweenChars;
    }

    displayGrid();
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("Start..."); 

    WiFi.onEvent(WiFiEvent);

    ETH.begin(
        ETH_ADDR,
        ETH_POWER_PIN,
        ETH_MDC_PIN,
        ETH_MDIO_PIN,
        ETH_TYPE,
        ETH_CLK_MODE
    );

    delay(2000);   // WICHTIG beim WT32-ETH01

    ETH.config(local_IP, gateway, subnet);

    while (!eth_connected) {
      Serial.println("Ethernet not yet ready");  
      delay(1000);
    }

    Serial.println("Ethernet ready!");

    postXml("http://192.168.0.11:8080/RetrieveLayout", layoutPayload);

    displayTextInMiddle("Hello");

    delay(10000);
}

void loop() {
    if (eth_connected) {
        grid.clear();

        unsigned long totalSeconds = millis() / 1000;
        
        unsigned long days    = totalSeconds / 86400;
        unsigned long hours   = (totalSeconds % 86400) / 3600;
        unsigned long minutes = (totalSeconds % 3600) / 60;
        unsigned long seconds = totalSeconds % 60;

        char buffer[8];
        snprintf(buffer, sizeof(buffer), "%02lu:%02lu", minutes, seconds);

        displayTextInMiddle(buffer);
    }
    else {
        Serial.println("Ethernet not connected");
    }
}