#pragma once
#include <experimental/memory>
#include "colors.hpp"

class RectangleActor {
    public:
        RectangleActor();
        RectangleActor(std::unique_ptr<SDL_Color> c, bool filled);
        RectangleActor(const SDL_Color& c, bool filled);
        std::unique_ptr<SDL_Color> color;
        bool filled;
    protected:
        void RDraw(SDL_Renderer* renderer, const std::experimental::observer_ptr<SDL_Rect>& rect);
};

template <class T>
void RectangleActorDraw(T& actor, SDL_Renderer* renderer);