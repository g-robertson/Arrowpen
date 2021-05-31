#pragma once

#include "refactor.hpp"
#include "rectangle.hpp"

class RefRectangleActor : public RectangleActor, public RefActor {
    public:
        RefRectangleActor(std::unique_ptr<SDL_Color> c, std::unique_ptr<SDL_Rect>& rect, bool filled = true);
        RefRectangleActor(const SDL_Color& c, std::unique_ptr<SDL_Rect>& rect, bool filled = true);

        void Draw(UPtrSDL_Renderer& renderer);
        NoHandle();
};