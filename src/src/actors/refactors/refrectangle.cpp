#include "refrectangle.hpp"

RefRectangleActor::RefRectangleActor(std::unique_ptr<SDL_Color> c, std::unique_ptr<SDL_Rect>& rect, bool filled) :
RectangleActor(std::move(c), filled), RefActor(rect) {}

RefRectangleActor::RefRectangleActor(const SDL_Color& c, std::unique_ptr<SDL_Rect>& rect, bool filled) :
RefRectangleActor(std::make_unique<SDL_Color>(c), rect, filled) {}

void RefRectangleActor::Draw(SDL_Renderer* renderer) {
    this->RDraw(renderer, this->rectg());
}