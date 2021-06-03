#pragma once

#include "actor.hpp"

class IntActor : public Actor {
    public:
        IntActor();
        IntActor(const SDL_Rect& rect);
        IntActor(std::unique_ptr<SDL_Rect> rect);
        IntActor(int x, int y, int w, int h);
        const SDL_Rect* rectg();
        std::unique_ptr<SDL_Rect> rect;
};