#pragma once
#include <memory>

#include "helpers.hpp"
#include "SDL2/SDL.h"

struct _SDL_DestroyWindow {
    void operator() (SDL_Window* window) {
        SDL_DestroyWindow(window);
    }
}; 

struct _SDL_DestroyRenderer {
    void operator() (SDL_Renderer* renderer) {
        SDL_DestroyRenderer(renderer);
    }
};

typedef std::unique_ptr<SDL_Window, _SDL_DestroyWindow> UPtrSDL_Window;
typedef std::unique_ptr<SDL_Renderer, _SDL_DestroyRenderer> UPtrSDL_Renderer;