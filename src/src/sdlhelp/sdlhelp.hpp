#pragma once
#include <memory>

#include "helpers.hpp"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"

struct SDL_Destroy {
    void operator() (SDL_Window* window) {
        SDL_DestroyWindow(window);
    }
    void operator() (SDL_Renderer* renderer) {
        SDL_DestroyRenderer(renderer);
    }
    void operator() (SDL_Texture* texture) {
        SDL_DestroyTexture(texture);
    }
    void operator() (TTF_Font* font) {
        TTF_CloseFont(font);
    }
}; 

typedef std::unique_ptr<SDL_Window, SDL_Destroy> UPtrSDL_Window;
typedef std::unique_ptr<SDL_Renderer, SDL_Destroy> UPtrSDL_Renderer;
typedef std::unique_ptr<SDL_Texture, SDL_Destroy> UPtrSDL_Texture;
typedef std::unique_ptr<TTF_Font, SDL_Destroy> UPtrTTF_Font;