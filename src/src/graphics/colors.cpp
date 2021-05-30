#include "helpers.hpp"
#include "colors.hpp"
#include <iostream>

void Colors::Scale(std::unique_ptr<SDL_Color>& color, float scale) {
    color->r = static_cast<Uint8>(std::round(std::min(255.0f, 255 - ((255 - color->r) * scale))));
    color->g = static_cast<Uint8>(std::round(std::min(255.0f, 255 - ((255 - color->g) * scale))));
    color->b = static_cast<Uint8>(std::round(std::min(255.0f, 255 - ((255 - color->b) * scale))));
}


// If passed a number <1 will make dark things darker and light things lighter
// If passed a number >1 will make dark things lighter and light things darker
void Colors::Contrast(std::unique_ptr<SDL_Color>& color, float contrast) {
    unsigned short total = Colors::Total(color);
    // inverts contrast if light color
    // 2->0.5
    // 0.5->2
    if (total < (256 * 3 / 2)) {
        contrast = 1 / contrast;
    }
    Colors::Scale(color, contrast);
}

std::unique_ptr<SDL_Color> Colors::Scale(const SDL_Color& color, float scale) {
    auto colorResult = std::make_unique<SDL_Color>(color);
    Colors::Scale(colorResult, scale);
    return colorResult;
}

std::unique_ptr<SDL_Color> Colors::Contrast(const SDL_Color& color, float scale) {
    auto colorResult = std::make_unique<SDL_Color>(color);
    Colors::Contrast(colorResult, scale);
    return colorResult;
}


unsigned short Colors::Total(const std::unique_ptr<SDL_Color>& color) {
    return color->r + color->g + color->b;
}