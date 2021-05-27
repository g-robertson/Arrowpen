#include "helpers.hpp"
#include "colors.hpp"
#include <iostream>

std::shared_ptr<SDL_Color> Colors::Scale(const SDL_Color& color, float scale) {
    return SharedNewPtr(SDL_Color, {
        static_cast<Uint8>(std::round(std::min(255.0f, 255 - ((255 - color.r) * scale)))),
        static_cast<Uint8>(std::round(std::min(255.0f, 255 - ((255 - color.g) * scale)))),
        static_cast<Uint8>(std::round(std::min(255.0f, 255 - ((255 - color.b) * scale)))),
        color.a});
}
// If passed a number <1 will make dark things darker and light things lighter
// If passed a number >1 will make dark things lighter and light things darker
std::shared_ptr<SDL_Color> Colors::Contrast(const SDL_Color& color, float contrast) {
    unsigned short total = Colors::Total(color);
    // inverts contrast if light color
    // 2->0.5
    // 0.5->2
    if (total < (256 * 3 / 2)) {
        contrast = 1 / contrast;
    }
    return Colors::Scale(color, contrast);
}


unsigned short Colors::Total(const SDL_Color& color) {
    return color.r + color.g + color.b;
}