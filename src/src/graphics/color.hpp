#pragma once
#include <cstdint>

class Color {
    public:
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
};