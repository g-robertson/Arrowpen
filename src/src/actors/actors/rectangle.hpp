#pragma once
#include <memory>

#include "colors.hpp"
#include "actor.hpp"

class RectangleActor : public Actor {
    public:
        RectangleActor(const SDL_Color& c, int x, int y, int w, int h, bool filled = true);
        void Draw(SDL_Renderer* renderer);
        NoHandle();

        std::shared_ptr<SDL_Rect> rect;
        std::shared_ptr<SDL_Color> color;
        bool filled;
};