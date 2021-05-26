#pragma once
#include <memory>

#include "color.hpp"
#include "actor.hpp"

class RectangleActor : public Actor {
    public:
        RectangleActor(const Color& c, int x, int y, int w, int h, bool filled = true);
        void Draw(SDL_Renderer* renderer);
        bool Handle(FullWindow* fullWindow, std::weak_ptr<SDL_Event> event);

        std::shared_ptr<SDL_Rect> rect;
        std::shared_ptr<Color> color;
        bool filled;
};