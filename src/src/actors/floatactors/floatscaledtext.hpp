#pragma once
#include "scaledtext.hpp"
#include "floatactor.hpp"

class FloatScaledTextActor : public FloatActor, public ScaledTextActor {
    public:
        FloatScaledTextActor(
            float x, float y, float w, float h,
            const char* text, const SDL_Color& textColor = Colors::BLACK, TTF_Font* font = Fonts::Sans.get()
        );
};