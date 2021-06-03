#include "intactor.hpp"

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

const SDL_Rect* IntActor::rectg() {
    return this->rect.get();
}