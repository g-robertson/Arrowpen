#pragma once

#include "refactor.hpp"
#include "rectangle.hpp"

class RefRectangleActor : public RefActor, public RectangleActor {
    public:
        RefRectangleActor(std::unique_ptr<SDL_Color> c, const SDL_Rect* rect, bool filled = true);
        RefRectangleActor(std::unique_ptr<SDL_Color> c, std::unique_ptr<SDL_Rect>& rect, bool filled = true);
        RefRectangleActor(const SDL_Color& c, std::unique_ptr<SDL_Rect>& rect, bool filled = true);
};