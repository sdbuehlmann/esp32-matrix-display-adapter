#include "Grid48x26.h"
#include <string.h>

// =====================
// Constructor
// =====================
Grid48x26::Grid48x26()
{
    clear();
}

// =====================
// Set bit
// (0,0) is top-left
//
// (0,0) ---------> x (0..25)
//  |
//  |
//  v
// y (0..47)
// =====================
void Grid48x26::set(uint8_t x, uint8_t y, bool value)
{
    if (x >= WIDTH || y >= HEIGHT)
        return;

    uint8_t& byte = data[y][x >> 3];
    uint8_t mask = (1 << (x & 7));

    if (value)
        byte |= mask;
    else
        byte &= ~mask;
}

// =====================
// Get bit
// =====================
bool Grid48x26::get(uint8_t x, uint8_t y) const
{
    if (x >= WIDTH || y >= HEIGHT)
        return false;

    return data[y][x >> 3] & (1 << (x & 7));
}

// =====================
// Clear grid (fast)
// =====================
void Grid48x26::clear()
{
    memset(data, 0, sizeof(data));
}

// =====================
// Export to 1-bit BMP (RAM)
// =====================
uint32_t Grid48x26::toBMP(uint8_t* out) const
{
    const int width = WIDTH;
    const int height = HEIGHT;
    const int gridRowSize = ROW_BYTES;

    // need to be 4-byte aligned (multiplier of 4)
    const int nrOfNeededWords = (width + 31) / 32;
    const int bmpRowSize = nrOfNeededWords * 4;

    const int pixelSize = bmpRowSize * height; // padded rows
    const int fileSize = 62 + pixelSize;

    // ---------------------
    // BMP FILE HEADER
    // ---------------------
    out[0] = 'B';
    out[1] = 'M';

    memcpy(out + 2, &fileSize, 4);

    uint32_t reserved = 0;
    memcpy(out + 6, &reserved, 4);

    uint32_t offset = 62;
    memcpy(out + 10, &offset, 4);

    // ---------------------
    // DIB HEADER
    // ---------------------
    uint32_t dibSize = 40;
    memcpy(out + 14, &dibSize, 4);

    int32_t w = width;
    int32_t h = height;

    memcpy(out + 18, &w, 4);
    memcpy(out + 22, &h, 4);

    uint16_t planes = 1;
    uint16_t bpp = 1;

    memcpy(out + 26, &planes, 2);
    memcpy(out + 28, &bpp, 2);

    uint32_t compression = 0;
    uint32_t imgSize = pixelSize;

    memcpy(out + 30, &compression, 4);
    memcpy(out + 34, &imgSize, 4);

    int32_t ppm = 2835;
    memcpy(out + 38, &ppm, 4);
    memcpy(out + 42, &ppm, 4);

    uint32_t colors = 2;
    uint32_t important = 0;

    memcpy(out + 46, &colors, 4);
    memcpy(out + 50, &important, 4);

    // ---------------------
    // PALETTE (black / white)
    // ---------------------
    out[54] = 0;   out[55] = 0;   out[56] = 0;   out[57] = 0;
    out[58] = 255; out[59] = 255; out[60] = 255; out[61] = 0;

    // ---------------------
    // PIXEL DATA
    // ---------------------
    uint8_t* pixel = out + 62;

    for (int y = 0; y < HEIGHT; y++)
    {
        int bmpY = HEIGHT - 1 - y;

        uint8_t* dst = &pixel[bmpY * bmpRowSize];

        // 6 Bytes echte Daten
        memcpy(dst, data[y], gridRowSize);

        // 2 Bytes Padding (WICHTIG)
        dst[6] = 0;
        dst[7] = 0;
    }

    return fileSize;
}