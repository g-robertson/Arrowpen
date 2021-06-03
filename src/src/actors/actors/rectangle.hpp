#pragma once

#include <experimental/memory>
#include "colors.hpp"
#include "sdlhelp.hpp"

class RectangleActor {
    public:
        RectangleActor();
        RectangleActor(std::unique_ptr<SDL_Color> c, bool filled);
        RectangleActor(const SDL_Color& c, bool filled);
        std::unique_ptr<SDL_Color> color;
        bool filled;
    protected:
        void RDraw(UPtrSDL_Renderer& renderer, const SDL_Rect* rect);
};