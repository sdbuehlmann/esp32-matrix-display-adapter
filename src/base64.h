#ifndef BASE64_H
#define BASE64_H

#include <stdint.h>
#include <stddef.h>

namespace base64 {

/// Berechnet die benötigte Output-Länge
constexpr size_t encodedLength(size_t inputLen) {
    return ((inputLen + 2) / 3) * 4;
}

/// Base64 encode (embedded-safe)
/// output muss groß genug sein!
size_t encode(const uint8_t* input,
              size_t inputLen,
              char* output);

} // namespace base64

#endif