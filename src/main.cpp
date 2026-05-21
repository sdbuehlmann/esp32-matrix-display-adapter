#include <Arduino.h>
#include <ETH.h>
#include <HTTPClient.h>

#include <font.h>
#include <renderer.h>
#include <base64.h>

#define ETH_ADDR        1
#define ETH_POWER_PIN   -1
#define ETH_MDC_PIN     23
#define ETH_MDIO_PIN    18
#define ETH_TYPE        ETH_PHY_LAN8720
// #define ETH_CLK_MODE    ETH_CLOCK_GPIO0_IN
#undef ETH_CLK_MODE
#define ETH_CLK_MODE    ETH_CLOCK_GPIO0_OUT

IPAddress local_IP(192, 168, 0, 43);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

bool eth_connected = false;

const char* layoutPayload = R"(<?xml version="1.0" encoding="UTF-8"?>
<MatrixDisplayService.RetrieveLayoutResponse>
  <LayoutData>
    <TimeStamp>
      <Value>2024-06-01T12:00:00Z</Value>
	</TimeStamp>
	<Layout>
	  <LayoutField>
	    <X><Value>0</Value></X>
		<Y><Value>0</Value></Y>
		<Width><Value>48</Value></Width>
		<Height><Value>26</Value></Height>
		<ContentRef><Value>1</Value></ContentRef>
	  </LayoutField>
	</Layout>
  </LayoutData>
</MatrixDisplayService.RetrieveLayoutResponse>)";

const char* contentPayload = R"(<?xml version="1.0" encoding="UTF-8"?>
<MatrixDisplayService.RetrieveContentResponse>
  <ContentData>
    <TimeStamp><Value>1970-01-02T00:04:50.0</Value></TimeStamp>
    <ContentRef><Value>1</Value></ContentRef>
    <Content>
      <ContentType>image/bmp</ContentType>
      <Data>Qk0OAQAAAAAAAD4AAAAoAAAAMAAAABoAAAABAAEAAAAAAAAAAAAAAAAAAAAAAAIAAAACAAAAAAAA//////8AAAADAiAAAAAAAAYCIAAAAAAAB//gAAAAAAAMAgAAAAAAAAwCAAAAAAAA+A+AAAAAAAAYGOAAAAAAABAQIAAAAAAB8DewAAAAAAAgZBAAAAAAAABBGAAAAAAAAMAYAAAAAAAAnMgAAAAAAADAyAAAAAAAAEAIAAB6U194cDgAAEJSUUh//AAAQlZXSEAEAABD1FBISEQAAEJfUUhYxAAAQlFZSHzsAABCU19IZ6gAAHpeTkhjOAAAAAAAAEMYAAAAAAAAQRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=</Data>
    </Content>
  </ContentData>
</MatrixDisplayService.RetrieveContentResponse>)";

void postXml(const char* url, const char* payload) {
    Serial.print("POST on ");
    Serial.println(url);
    Serial.println("Payload:");
    Serial.println(payload);

    HTTPClient http;

    http.begin(url);
    http.addHeader("Content-Type", "application/xml");

    int httpCode = http.POST((uint8_t*)payload, strlen(payload));

    Serial.println("-----------------------------------");
    Serial.print("HTTP Code: ");
    Serial.println(httpCode);

    if (httpCode > 0)
    {
        String response = http.getString();

        Serial.println("Response:");

        if (response.length() > 0)
        {
            Serial.println(response);
        }
        else
        {
            Serial.println("(empty)");
        }
    }
    else
    {
        Serial.print("POST failed: ");
        Serial.println(http.errorToString(httpCode));
    }

    http.end();
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

void convert(char c) {
    Serial.println("######################################################");
    Serial.print("Convert to .bmp (Base64 encoded): ");
    Serial.println(c);

    const Bitmap* bmp = getBitmap(c);
    bool ok = BitmapToBMP(*bmp, buffer, sizeof(buffer));

    if (ok) {
        uint32_t rowSize = ((bmp->width + 7) / 8 + 3) & ~3u;
        uint32_t bmpSize = 14 + 40 + 8 + rowSize * bmp->height;

        char base64Buffer[128];
        size_t base64Len = base64::encode(buffer, bmpSize, base64Buffer);
        base64Buffer[base64Len] = '\0';

        Serial.println("Result:");
        Serial.println(base64Buffer);
    } else {
        Serial.println("!!BMP conversion failed!!");
    }

    Serial.println("");
}

void setup()
{
    Serial.begin(115200);

    delay(10000);
    Serial.println("Start booting..."); 

    convert('A');
    convert('B');
    convert('C');
    convert('4');
    convert('2');

    delay(10000);

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

    Serial.println("Set layout...");
    postXml("http://192.168.0.11:8080/RetrieveLayout", layoutPayload);

    delay(2000);
}

void loop()
{
    if (eth_connected)
    {
        Serial.println("Set content...");
        postXml("http://192.168.0.11:8080/RetrieveContent", contentPayload);
    }
    else
    {
        Serial.println("Ethernet not connected");
    }

    delay(5000);
}