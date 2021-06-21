#include "rectangle.hpp"



template <class T>
RectangleActor<T>::RectangleActor(T* actor, std::unique_ptr<SDL_Color> c, bool filled) :
TypedActor<T>(actor) {
    this->color = std::move(c);
    this->filled = filled;
}

template <class T>
RectangleActor<T>::RectangleActor(std::unique_ptr<SDL_Color> c, bool filled) :
RectangleActor::RectangleActor(new T(), std::move(c), filled) {}

TemplateAllActorsAndNone(RectangleActor, std::unique_ptr<SDL_Color> c, bool filled);


template <class T>
RectangleActor<T>::RectangleActor(T* actor, const SDL_Color& c, bool filled) :
RectangleActor::RectangleActor(actor, std::make_unique<SDL_Color>(c), filled) {}

template <class T>
RectangleActor<T>::RectangleActor(const SDL_Color& c, bool filled) :
RectangleActor::RectangleActor(std::make_unique<SDL_Color>(c), filled) {}

TemplateAllActorsAndNone(RectangleActor, const SDL_Color& c, bool filled);


template <class T>
void RectangleActor<T>::Draw(UPtrSDL_Renderer& renderer) {
    SDL_SetRenderDrawColor(renderer.get(), ExpandColor(this->color));
    if (this->filled) {
        SDL_RenderFillRect(renderer.get(), this->rectg());
    } else {
        SDL_RenderDrawRect(renderer.get(), this->rectg());
    }
}
