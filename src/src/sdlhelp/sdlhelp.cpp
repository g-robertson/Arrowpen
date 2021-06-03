#include "sdlhelp.hpp"

SDL_Context::SDL_Context(UPtrSDL_Window window) {
    this->window = std::move(window);
    this->renderer = UPtrSDL_Renderer(SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED));
}