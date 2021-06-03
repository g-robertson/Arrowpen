#pragma once
#include <memory>

#include "colors.hpp"
#include "intactor.hpp"
#include "rectangle.hpp"

class IntRectangleActor : public RectangleActor, public IntActor {
    public:
        IntRectangleActor(const SDL_Color& c, bool filled = true);
        IntRectangleActor(const SDL_Color& c, SDL_Rect& rect, bool filled = true);
        IntRectangleActor(const SDL_Color& c, int x, int y, int w, int h, bool filled = true);

        void Draw(UPtrSDL_Renderer& renderer);
        NoHandle();
};