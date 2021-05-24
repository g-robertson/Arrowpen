#pragma once

#include "SDL2/SDL.h"

class Actor{
    public:
        virtual void Draw(SDL_Renderer* renderer) = 0;
};