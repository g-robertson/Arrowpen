#pragma once
#include "floatactor.hpp"
#include "rectangle.hpp"

class FloatRectangleActor : public FloatActor, public RectangleActor {
    public:
        FloatRectangleActor(const SDL_Color& c, float x, float y, float w, float h, bool filled = true);
        void Draw(SDL_Renderer* renderer);
        NoHandle();
};