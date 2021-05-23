#pragma once
#include "SDL2/SDL.h"

struct _SDL_DestroyWindow {
    void operator() (SDL_Window* window) {
        SDL_DestroyWindow(window);
    }
}; 