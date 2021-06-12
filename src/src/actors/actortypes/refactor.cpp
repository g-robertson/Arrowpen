#include "refactor.hpp"

RefActor::RefActor() {}

RefActor::RefActor(const SDL_Rect* rect) {
    this->rect = rect;
}

RefActor::RefActor(const std::unique_ptr<SDL_Rect>& rect) {
    this->rect = rect.get();
}