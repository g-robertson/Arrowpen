#pragma once
#include "actor.hpp"
#include "colors.hpp"

class RectangleActor : virtual public Actor {
    public:
        RectangleActor();
        RectangleActor(std::unique_ptr<SDL_Color> c, bool filled);
        RectangleActor(const SDL_Color& c, bool filled);
        std::unique_ptr<SDL_Color> color;
        bool filled;

        void Draw(UPtrSDL_Renderer& renderer);
};