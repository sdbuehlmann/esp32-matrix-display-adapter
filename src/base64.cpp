#include "base64.h"

namespace base64 {

static const char table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

size_t encode(const uint8_t* input,
              size_t inputLen,
              char* output)
{
    size_t i = 0;
    size_t o = 0;

    while (i < inputLen) {
        uint32_t a = i < inputLen ? input[i++] : 0;
        uint32_t b = i < inputLen ? input[i++] : 0;
        uint32_t c = i < inputLen ? input[i++] : 0;

        uint32_t triple = (a << 16) | (b << 8) | c;

        output[o++] = table[(triple >> 18) & 0x3F];
        output[o++] = table[(triple >> 12) & 0x3F];
        output[o++] = table[(triple >> 6) & 0x3F];
        output[o++] = table[triple & 0x3F];
    }

    // Padding
    size_t mod = inputLen % 3;
    if (mod) {
        output[o - 1] = '=';
        if (mod == 1) {
            output[o - 2] = '=';
        }
    }

    return o;
}

} // namespace base64