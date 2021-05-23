#pragma once
#include "SDL2/SDL.h"

#include "textbox.hpp"

class Graphics {
    public:
        Graphics();
        void Draw(SDL_Window* window);
};