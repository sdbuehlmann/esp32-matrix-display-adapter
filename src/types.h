#pragma once

#include <Arduino.h>

/**
 * Represents a monochrome bitmap image.
 *
 * Pixel data is stored as a continuous bit-packed stream
 * in row-major order, starting at the top-left corner.
 *
 * Bit layout:
 * - Pixels are stored left-to-right, top-to-bottom.
 * - The most significant bit (MSB) of each byte comes first.
 * - Rows are NOT byte-aligned.
 * - Bits continue seamlessly across byte boundaries.
 *
 * Example for a 5x7 bitmap:
 *
 * <x,y> describes the pixel coordinates,
 * where (0,0) is the top-left corner.
 *
 * byte[0]:
 *   <0,0><1,0><2,0><3,0><4,0><0,1><1,1><2,1>
 *
 * byte[1]:
 *   <3,1><4,1><0,2><1,2><2,2><3,2><4,2><0,3>
 *
 * etc.
 *
 * Unused bits may exist in the final byte if
 * width * height is not divisible by 8.
 */
struct Bitmap
{
    /// Width of the bitmap in pixels.
    uint8_t width;

    /// Height of the bitmap in pixels.
    uint8_t height;

    /**
     * Pointer to the bit-packed pixel data.
     *
     * Each pixel is represented by a single bit:
     * - 0 = background/off
     * - 1 = foreground/on
     */
    const uint8_t* data;

    bool get(uint8_t x, uint8_t y) const
    {
        if (x >= width || y >= height) return false;

        uint32_t bitIndex = y * width + x;
        uint32_t byteIndex = bitIndex >> 3; // divided by 8
        uint8_t bitOffset = 7 - (bitIndex & 7); // MSB-first

        return data[byteIndex] & (1 << bitOffset);
    }
};