#pragma once

#include <Arduino.h>
#include <string.h>

template <uint8_t W, uint8_t H>
class Grid
{
public:
    static constexpr uint8_t WIDTH = W;
    static constexpr uint8_t HEIGHT = H;

    static constexpr uint8_t ROW_BYTES = (W + 7) / 8;

private:
    uint8_t data[HEIGHT][ROW_BYTES] = {0};

public:
    // =====================
// Set bit
// (0,0) is top-left
//
// (0,0) ---------> x (0..W)
//  |
//  |
//  v
// y (0..H)
// =====================
    void set(uint8_t x, uint8_t y, bool value)
    {
        if (x >= WIDTH || y >= HEIGHT) return;

        uint8_t& byte = data[y][x >> 3];
        uint8_t mask = (1 << (x & 7));

        if (value) byte |= mask;
        else       byte &= ~mask;
    }

    // =====================
    // GET
    // =====================
    bool get(uint8_t x, uint8_t y) const
    {
        if (x >= WIDTH || y >= HEIGHT) return false;

        return data[y][x >> 3] & (1 << (x & 7));
    }

    // =====================
    // CLEAR
    // =====================
    void clear()
    {
        memset(data, 0, sizeof(data));
    }

    // =====================
    // BMP EXPORT
    // =====================
    uint32_t toBMP(uint8_t* out) const
    {
        constexpr uint32_t bmpRowSize =
            ((WIDTH + 31) / 32) * 4;   // 4-byte aligned rows

        const uint32_t pixelSize = bmpRowSize * HEIGHT;
        const uint32_t fileSize  = 62 + pixelSize;

        // ---- FILE HEADER ----
        out[0] = 'B';
        out[1] = 'M';

        memcpy(out + 2, &fileSize, 4);

        uint32_t reserved = 0;
        memcpy(out + 6, &reserved, 4);

        uint32_t offset = 62;
        memcpy(out + 10, &offset, 4);

        // ---- DIB HEADER ----
        uint32_t dibSize = 40;
        memcpy(out + 14, &dibSize, 4);

        int32_t w = WIDTH;
        int32_t h = HEIGHT;

        memcpy(out + 18, &w, 4);
        memcpy(out + 22, &h, 4);

        uint16_t planes = 1;
        uint16_t bpp = 1;

        memcpy(out + 26, &planes, 2);
        memcpy(out + 28, &bpp, 2);

        uint32_t compression = 0;
        memcpy(out + 30, &compression, 4);

        uint32_t imgSize = pixelSize;
        memcpy(out + 34, &imgSize, 4);

        int32_t ppm = 2835;
        memcpy(out + 38, &ppm, 4);
        memcpy(out + 42, &ppm, 4);

        uint32_t colors = 2;
        uint32_t important = 0;

        memcpy(out + 46, &colors, 4);
        memcpy(out + 50, &important, 4);

        // ---- PALETTE ----
        out[54] = 0;   out[55] = 0;   out[56] = 0;   out[57] = 0;
        out[58] = 255; out[59] = 255; out[60] = 255; out[61] = 0;

        // ---- PIXEL DATA ----
        uint8_t* pixel = out + 62;

        for (uint8_t y = 0; y < HEIGHT; y++)
        {
            uint8_t bmpY = HEIGHT - 1 - y;
            uint8_t* dst = &pixel[bmpY * bmpRowSize];

            memcpy(dst, data[y], ROW_BYTES);

            // BMP padding
            for (uint8_t i = ROW_BYTES; i < bmpRowSize; i++)
                dst[i] = 0;
        }

        return fileSize;
    }
};