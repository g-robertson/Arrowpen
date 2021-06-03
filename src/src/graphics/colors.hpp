#pragma once
#include <memory>
#include <cstdint>
#include "SDL2/SDL.h"

#define ExpandColorSymbol_(color, symbol) color symbol r, color symbol g, color symbol b, color symbol a
#define ExpandColor(color) ExpandColorSymbol_(color, ->)
#define ExpandColorDot(color) ExpandColorSymbol_(color, .)

#define ColorA(red, green, blue, alpha) SDL_Color {red, green, blue, alpha}
#define Color(red, green, blue) SDL_Color {red, green, blue, 255}

namespace Colors {
    void Scale(std::unique_ptr<SDL_Color>& color, float scale);
    void Contrast(std::unique_ptr<SDL_Color>& color, float contrast);
    std::unique_ptr<SDL_Color> Scale(const SDL_Color& color, float scale);
    std::unique_ptr<SDL_Color> Contrast(const SDL_Color& color, float contrast);
    unsigned short Total(const std::unique_ptr<SDL_Color>& color);

    #define NColorA(name, r, g, b, a) constexpr static SDL_Color name = ColorA(r, g, b, a)
    #define NColor(name, r, g, b) constexpr static SDL_Color name = Color(r, g, b)
    #define GRAY(hex) NColor(GRAY ## hex, 0x ## hex, 0x ## hex, 0x ## hex)
    GRAY(CF);
    GRAY(AF);
    GRAY(9F);
    GRAY(7F);
    GRAY(5F);
    GRAY(3F);
    GRAY(1F);
    #undef GRAY

    // I cannot divine why, but pure white copies to clipboard as transparent, so until I figure out a correct fix
    // white will be #FEFEFE
    NColorA(TRANSPARENT, 0, 0, 0, 0);
    NColor(WHITE, 254, 254, 254);
    NColor(BLACK, 0, 0, 0);

    // Primaries
    NColor(RED, 255, 0, 0);
    NColor(GREEN, 0, 255, 0);
    NColor(BLUE, 0, 0, 255);

    // Secondaries
    NColor(YELLOW, 255, 255, 0);
    NColor(PURPLE, 255, 0, 255);
    NColor(CYAN, 0, 255, 255);

    // Tertiaries
    NColor(ORANGE, 255, 127, 0);
    NColor(PINK, 255, 0, 127);
    NColor(SALMON, 255, 127, 127);
    
    NColor(CHARTREUSE, 127, 255, 0);
    NColor(SPRING_GREEN, 0, 255, 127);
    NColor(LIGHT_GREEN, 127, 255, 127);

    NColor(INDIGO, 127, 0, 255);
    NColor(AZURE, 0, 127, 255);
    NColor(CORNFLOWER_BLUE, 127, 127, 255);

    NColor(LIGHT_YELLOW, 255, 255, 127);
    NColor(LIGHT_PURPLE, 255, 127, 255);
    NColor(LIGHT_CYAN, 127, 255, 255);


    // Common Use
    constexpr static SDL_Color ERROR = PURPLE;
    constexpr static SDL_Color DARKTHEME_TEXT = GRAYAF;
    constexpr static SDL_Color DARKTHEME_BACKGROUND = GRAY1F;

    #undef NColor
    #undef NColorA
}