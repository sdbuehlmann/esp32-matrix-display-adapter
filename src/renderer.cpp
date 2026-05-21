#include <renderer.h>

struct BMPFileHeader
{
    uint16_t bfType;      // "BM"
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};

struct BMPInfoHeader
{
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};

static inline uint32_t bmpRowSize(uint8_t width)
{
    // bits -> bytes, padded to 4-byte boundary
    uint32_t bytes = (width + 7) / 8;
    return (bytes + 3) & ~3;
}

/**
 * outBuffer muss groß genug sein:
 * 14 + 40 + 8 + rowSize * height
 */
bool BitmapToBMP(const Bitmap& src, uint8_t* outBuffer, uint32_t outSize)
{
    const uint32_t rowSize = bmpRowSize(src.width);
    const uint32_t pixelDataSize = rowSize * src.height;
    const uint32_t totalSize = 14 + 40 + 8 + pixelDataSize;

    if (outSize < totalSize) return false;

    uint8_t* p = outBuffer;

    // ===== FILE HEADER =====
    BMPFileHeader fileHeader;
    fileHeader.bfType = 0x4D42; // 'BM'
    fileHeader.bfSize = totalSize;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = 14 + 40 + 8;

    memcpy(p, &fileHeader, 14);
    p += 14;

    // ===== INFO HEADER =====
    BMPInfoHeader infoHeader;
    memset(&infoHeader, 0, sizeof(infoHeader));

    infoHeader.biSize = 40;
    infoHeader.biWidth = src.width;
    infoHeader.biHeight = src.height; // bottom-up
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 1;
    infoHeader.biCompression = 0;
    infoHeader.biSizeImage = pixelDataSize;
    infoHeader.biXPelsPerMeter = 2835;
    infoHeader.biYPelsPerMeter = 2835;
    infoHeader.biClrUsed = 2;
    infoHeader.biClrImportant = 2;

    memcpy(p, &infoHeader, 40);
    p += 40;

    // ===== PALETTE (black/white) =====
    // BMP: BGRA format
    uint8_t palette[8] =
    {
        0x00, 0x00, 0x00, 0x00, // black
        0xFF, 0xFF, 0xFF, 0x00  // white
    };

    memcpy(p, palette, 8);
    p += 8;

    // ===== PIXEL DATA =====
    memset(p, 0, pixelDataSize);

    const uint8_t bytesPerRowSrc = (src.width + 7) / 8;

    for (uint8_t y = 0; y < src.height; y++)
    {
        // BMP ist bottom-up
        uint8_t srcRow = src.height - 1 - y;

        uint8_t* dstRow = p + y * rowSize;
        const uint8_t* srcRowPtr = src.data + srcRow * bytesPerRowSrc;

        memcpy(dstRow, srcRowPtr, bytesPerRowSrc);
    }

    return true;
}