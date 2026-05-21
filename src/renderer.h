// renderer.h
#pragma once

#include <stdint.h>
#include <string.h>
#include <types.h>

/**
 * outBuffer muss groß genug sein:
 * 14 + 40 + 8 + rowSize * height
 */
bool BitmapToBMP(const Bitmap& src, uint8_t* outBuffer, uint32_t outSize);
