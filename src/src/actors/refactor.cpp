#include "refactor.hpp"

RefActor::RefActor() {}

RefActor::RefActor(const std::unique_ptr<SDL_Rect>& rect) {
    this->rect = rect.get();
}

const SDL_Rect* RefActor::rectg() {
    return this->rect;
}