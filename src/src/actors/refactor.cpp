#include "refactor.hpp"

RefActor::RefActor() {}

RefActor::RefActor(const std::unique_ptr<SDL_Rect>& rect) {
    this->rect = std::experimental::make_observer(rect.get());
}

const std::experimental::observer_ptr<SDL_Rect> RefActor::rectg() {
    return this->rect;
}