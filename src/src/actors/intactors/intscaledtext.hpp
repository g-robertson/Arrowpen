#pragma once

#include "scaledtext.hpp"
#include "intactor.hpp"

class IntScaledTextActor : public IntActor, public ScaledTextActor {
    public:
        IntScaledTextActor(const char* text, const SDL_Color& textColor, TTF_Font* font);
        IntScaledTextActor(
            int x, int y, int w, int h,
            const char* text, const SDL_Color& textColor = Colors::BLACK, TTF_Font* font = Fonts::Sans.get()
        );
};