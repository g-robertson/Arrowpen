#pragma once
#include "actor.hpp"
#include "fonts.hpp"
#include "colors.hpp"

class ScaledTextActor : virtual public Actor {
    public:
        ScaledTextActor(
            const char* text, const SDL_Color& textColor = Colors::BLACK, TTF_Font* font = Fonts::Sans.get()
        );
        void Draw(UPtrSDL_Renderer& renderer);
        std::list<UPtrSDL_Texture> Init(UPtrSDL_Renderer& renderer);
    private:
        union {
            SDL_Surface* surface;
            SDL_Texture* texture;
        };
};