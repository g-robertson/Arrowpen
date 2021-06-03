#pragma once
#include <memory>

#include "helpers.hpp"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"

struct SDL_Destroy {
    void operator() (SDL_Window* window) {
        if (window != nullptr) {
            SDL_DestroyWindow(window);
        }
    }
    void operator() (SDL_Renderer* renderer) {
        if (renderer != nullptr) {
            SDL_DestroyRenderer(renderer);
        }
    }
    void operator() (SDL_Texture* texture) {
        if (texture != nullptr) {
            SDL_DestroyTexture(texture);
        }
    }
    void operator() (SDL_Surface* surface) {
        if (surface != nullptr) {
            SDL_FreeSurface(surface);
        }
    }
    void operator() (TTF_Font* font) {
        if (font != nullptr) {
            TTF_CloseFont(font);
        }
    }
}; 

typedef std::unique_ptr<SDL_Window, SDL_Destroy> UPtrSDL_Window;
typedef std::unique_ptr<SDL_Renderer, SDL_Destroy> UPtrSDL_Renderer;
typedef std::unique_ptr<SDL_Surface, SDL_Destroy> UPtrSDL_Surface;
typedef std::unique_ptr<SDL_Texture, SDL_Destroy> UPtrSDL_Texture;
typedef std::unique_ptr<TTF_Font, SDL_Destroy> UPtrTTF_Font;

class SDL_Context {
    public:
        SDL_Context(UPtrSDL_Window window);
        UPtrSDL_Window window;
        UPtrSDL_Renderer renderer;
};