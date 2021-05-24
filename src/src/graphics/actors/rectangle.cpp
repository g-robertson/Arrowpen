#include "rectangle.hpp"
#include "SDL2/SDL.h"
#include <iostream>
RectangleActor::RectangleActor(Color* c, int x, int y, int w, int h, bool filled) {
    this->rect = std::shared_ptr<SDL_Rect>(new SDL_Rect {x, y, w, h});
    this->color = std::shared_ptr<Color>(c);
    this->filled = filled;
}

void RectangleActor::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, ExpandColor(this->color));
    SDL_RenderFillRect(renderer, this->rect.get());
    SDL_RenderPresent(renderer);
}