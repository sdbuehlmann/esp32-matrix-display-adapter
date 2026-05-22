#ifndef GRID48X26_H
#define GRID48X26_H

#include <Arduino.h>

class Grid48x26
{
public:
    static constexpr int WIDTH = 48;
    static constexpr int HEIGHT = 26;
    static constexpr int ROW_BYTES = (WIDTH + 7) / 8; // = 4

    Grid48x26();

    void set(uint8_t x, uint8_t y, bool value);
    bool get(uint8_t x, uint8_t y) const;

    void clear();

    uint32_t toBMP(uint8_t* outBuffer) const;

private:
    uint8_t data[HEIGHT][ROW_BYTES];
};

#endif