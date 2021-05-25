#pragma once
#include <memory>
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

namespace Colors {
    const Color TRANSPARENT = Color(0, 0, 0, 0);

    const Color BLACK = Color(0, 0, 0);
    #define GRAY(hex) const Color GRAY ## hex = Color(0x ## hex, 0x ## hex, 0x ## hex)
    GRAY(CF);
    GRAY(AF);
    GRAY(9F);
    GRAY(7F);
    GRAY(5F);
    GRAY(3F);
    GRAY(1F);
    #undef GRAY

    const Color WHITE = Color(255, 255, 255);
    
    const Color RED = Color(255, 0, 0);
    const Color GREEN = Color(0, 255, 0);
    const Color BLUE = Color(0, 0, 255);

    const Color YELLOW = Color(255, 255, 0);
    const Color PURPLE = Color(255, 0, 255);
    const Color VIOLET = PURPLE;
    const Color CYAN = Color(0, 255, 255);

    const Color ORANGE = Color(255, 127, 0);
    const Color PINK = Color(255, 0, 127);
    const Color CHARTREUSE = Color(127, 255, 0);
    const Color SPRING_GREEN = Color(0, 255, 127);
    const Color INDIGO = Color(127, 0, 255);
    const Color AZURE = Color(0, 127, 255);
}