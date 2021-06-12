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

void RectangleActor::Draw(UPtrSDL_Renderer& renderer) {
    SDL_SetRenderDrawColor(renderer.get(), ExpandColor(this->color));
    if (this->filled) {
        SDL_RenderFillRect(renderer.get(), this->rectg());
    } else {
        SDL_RenderDrawRect(renderer.get(), this->rectg());
    }
}