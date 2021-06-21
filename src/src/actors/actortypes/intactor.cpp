#include "intactor.hpp"
#include "typedactor.hpp"

IntActor::IntActor() {
    this->rect = std::make_unique<SDL_Rect>(SDL_Rect());
}

IntActor::IntActor(const SDL_Rect& rect) {
    this->rect = std::make_unique<SDL_Rect>(rect);
}

IntActor::IntActor(std::unique_ptr<SDL_Rect> rect) {
    this->rect = std::move(rect);
}

IntActor::IntActor(int x, int y, int w, int h) {
    this->rect = std::make_unique<SDL_Rect>(SDL_Rect{x, y, w, h});
}

void TypedActor<IntActor>::rects(int x, int y, int w, int h) {
    this->actor->rects(x, y, w, h);
    this->rectsCallback(x, y, w, h);
}

void IntActor::rects(int x, int y, int w, int h) {
    this->rect->x = x;
    this->rect->y = y;
    this->rect->w = w;
    this->rect->h = h;
}