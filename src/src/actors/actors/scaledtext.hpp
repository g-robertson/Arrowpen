#pragma once
#include <list>
#include "typedactor.hpp"
#include "fonts.hpp"
#include "colors.hpp"

template <class T>
class ScaledTextActor : virtual public TypedActor<T> {
    public:
        ScaledTextActor(
            const char* text,
            const SDL_Color& color = Colors::BLACK,
            TTF_Font* = Fonts::Sans.get()
        );
        ScaledTextActor(
            T* actor,
            const char* text,
            const SDL_Color& color = Colors::BLACK,
            TTF_Font* = Fonts::Sans.get()
        );
        void Draw(UPtrSDL_Renderer& renderer);
        std::list<UPtrSDL_Texture> Init(UPtrSDL_Renderer& renderer);
    private:
        union {
            SDL_Surface* surface;
            SDL_Texture* texture;
        };
};