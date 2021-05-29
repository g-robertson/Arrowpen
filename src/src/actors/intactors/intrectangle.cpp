#include "helpers.hpp"
#include "intrectangle.hpp"

#include "SDL2/SDL.h"


IntRectangleActor::IntRectangleActor(const SDL_Color& c, bool filled) {
    this->color = SharedNewPtr(SDL_Color, c);
    this->rect = SharedNewPtr(SDL_Rect);
    this->filled = filled;
}

IntRectangleActor::IntRectangleActor(const SDL_Color& c, std::shared_ptr<SDL_Rect> rect, bool filled) {
    this->color = SharedNewPtr(SDL_Color, c);
    this->rect = rect;
    this->filled = filled;
}

IntRectangleActor::IntRectangleActor(const SDL_Color& c, int x, int y, int w, int h, bool filled) {
    this->color = SharedNewPtr(SDL_Color, c);
    this->rect = SharedNewPtr(SDL_Rect, {x, y, w, h});
    this->filled = filled;
}

void IntRectangleActor::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, ExpandColor(this->color));
    if (this->filled) {
        SDL_RenderFillRect(renderer, this->rect.get());
    } else {
        SDL_RenderDrawRect(renderer, this->rect.get());
    }
}