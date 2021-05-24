#pragma once
#include <memory>

#include "color.hpp"
#include "actor.hpp"

class RectangleActor : public Actor {
    public:
        RectangleActor(Color* c, int x, int y, int w, int h, bool filled = true);
        void Draw(SDL_Renderer* renderer);

        std::shared_ptr<SDL_Rect> rect;
        std::shared_ptr<Color> color;
        bool filled;
};