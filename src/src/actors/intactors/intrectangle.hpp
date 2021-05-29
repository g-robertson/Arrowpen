#pragma once
#include <memory>

#include "colors.hpp"
#include "intactor.hpp"

class IntRectangleActor : public IntActor {
    public:
        IntRectangleActor(const SDL_Color& c, bool filled = true);
        IntRectangleActor(const SDL_Color& c, std::shared_ptr<SDL_Rect> rect, bool filled = true);
        IntRectangleActor(const SDL_Color& c, int x, int y, int w, int h, bool filled = true);
        void Draw(SDL_Renderer* renderer);
        NoHandle();

        std::shared_ptr<SDL_Color> color;
        bool filled;

        std::shared_ptr<SDL_Rect> rect;
};