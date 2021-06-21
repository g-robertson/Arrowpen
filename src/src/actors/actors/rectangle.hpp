#pragma once
#include "typedactor.hpp"
#include "colors.hpp"

template <class T>
class RectangleActor : virtual public TypedActor<T> {
    public:
        RectangleActor(T* actor, std::unique_ptr<SDL_Color> c, bool filled = true);
        RectangleActor(T* actor, const SDL_Color& c, bool filled = true);
        RectangleActor(std::unique_ptr<SDL_Color> c, bool filled = true);
        RectangleActor(const SDL_Color& c, bool filled = true);
        
        std::unique_ptr<SDL_Color> color;
        bool filled;
        void Draw(UPtrSDL_Renderer& renderer);
};