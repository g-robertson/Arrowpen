#pragma once
#include <memory>

#include "colors.hpp"
#include "floatactor.hpp"

class RectangleActor : public FloatActor {
    public:
        RectangleActor(const SDL_Color& c, float x, float y, float w, float h, bool filled = true);
        void Draw(SDL_Renderer* renderer);
        NoHandle();

        std::shared_ptr<SDL_Color> color;
        bool filled;
};