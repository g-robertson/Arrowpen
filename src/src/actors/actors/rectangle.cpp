#include "rectangle.hpp"
#include "intrectangle.hpp"
#include "floatrectangle.hpp"
#include "refrectangle.hpp"

RectangleActor::RectangleActor() {}

RectangleActor::RectangleActor(std::unique_ptr<SDL_Color> c, bool filled) {
    this->color = std::move(c);
    this->filled = filled;
}

RectangleActor::RectangleActor(const SDL_Color& c, bool filled) :
RectangleActor::RectangleActor(std::make_unique<SDL_Color>(c), filled) {}

void RectangleActor::RDraw(UPtrSDL_Renderer& renderer, const std::experimental::observer_ptr<SDL_Rect>& rect) {
    SDL_SetRenderDrawColor(renderer.get(), ExpandColor(this->color));
    if (this->filled) {
        SDL_RenderFillRect(renderer.get(), rect.get());
    } else {
        SDL_RenderDrawRect(renderer.get(), rect.get());
    }
}