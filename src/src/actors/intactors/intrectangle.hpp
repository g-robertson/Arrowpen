#pragma once
#include <memory>

#include "colors.hpp"
#include "intactor.hpp"
#include "rectangle.hpp"

class IntRectangleActor : public IntActor, public RectangleActor {
    public:
        IntRectangleActor(const SDL_Color& c, bool filled = true);
        IntRectangleActor(const SDL_Color& c, SDL_Rect& rect, bool filled = true);
        IntRectangleActor(const SDL_Color& c, int x, int y, int w, int h, bool filled = true);

        void Draw(SDL_Renderer* renderer);
        NoHandle();
};