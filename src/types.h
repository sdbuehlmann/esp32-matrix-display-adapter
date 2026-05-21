#pragma once

#include <Arduino.h>

struct Bitmap
{
    uint8_t width;
    uint8_t height;
    const uint8_t* data; // bit-packed, row-major, MSB first
};