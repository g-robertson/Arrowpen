#pragma once
#include <cstdint>

#define ExpandColor(color) color->red, color->green, color->blue, color->alpha

class Color {
    public:
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
};