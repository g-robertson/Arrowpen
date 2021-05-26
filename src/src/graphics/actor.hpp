#pragma once

#include <memory>
#include "SDL2/SDL.h"

class FullWindow;

class Actor {
    public:
        virtual void Draw(SDL_Renderer* renderer) = 0;
        virtual bool Handle(FullWindow* fullWindow, std::weak_ptr<SDL_Event> event) = 0;
};