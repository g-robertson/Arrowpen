#pragma once
#include <memory>
#include "SDL2/SDL.h"

class OwningActor {
    public:
        const SDL_Rect* rectg() {return this->rect.get();}
    protected:
        std::unique_ptr<SDL_Rect> rect;
};