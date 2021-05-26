#pragma once
#include <memory>

#include "helpers.hpp"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"

struct _SDL_Destroy {
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

typedef std::unique_ptr<SDL_Window, _SDL_Destroy> UPtrSDL_Window;
typedef std::unique_ptr<SDL_Renderer, _SDL_Destroy> UPtrSDL_Renderer;
typedef std::unique_ptr<SDL_Texture, _SDL_Destroy> UPtrSDL_Texture;
typedef std::unique_ptr<TTF_Font, _SDL_Destroy> UPtrTTF_Font;