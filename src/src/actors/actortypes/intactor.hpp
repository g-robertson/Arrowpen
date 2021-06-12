#pragma once

#include "owningactor.hpp"

class IntActor : virtual public OwningActor {
    public:
        IntActor();
        IntActor(const SDL_Rect& rect);
        IntActor(std::unique_ptr<SDL_Rect> rect);
        IntActor(int x, int y, int w, int h);

        void rects(int x, int y, int w, int h);
};