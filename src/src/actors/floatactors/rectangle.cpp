#include "helpers.hpp"
#include "rectangle.hpp"

#include "SDL2/SDL.h"


RectangleActor::RectangleActor(const SDL_Color& c, float x, float y, float w, float h, bool filled) : FloatActor(x, y, w, h) {
    this->color = SharedNewPtr(SDL_Color, c);
    this->filled = filled;
}

void RectangleActor::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, ExpandColor(this->color));
    if (this->filled) {
        SDL_RenderFillRect(renderer, this->rect.get());
    } else {
        SDL_RenderDrawRect(renderer, this->rect.get());
    }
}