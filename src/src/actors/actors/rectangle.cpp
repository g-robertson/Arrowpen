#include "helpers.hpp"
#include "rectangle.hpp"

#include "SDL2/SDL.h"

#include <iostream>

RectangleActor::RectangleActor(const Color& c, int x, int y, int w, int h, bool filled) {
    this->rect = SharedNewPtr(SDL_Rect, {x, y, w, h});
    this->color = SharedNewPtr(Color, c);
    this->filled = filled;
}

void RectangleActor::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, ExpandColor(this->color));
    SDL_RenderFillRect(renderer, this->rect.get());
}