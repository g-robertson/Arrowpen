#pragma once
#include <string>

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"

#include "fonts.hpp"
#include "floatactor.hpp"
#include "colors.hpp"

class FloatScaledTextActor : public FloatActor {
    public:
        FloatScaledTextActor(
            float x, float y, float w, float h,
            const char* text, const SDL_Color& textColor = Colors::BLACK, TTF_Font* font = Fonts::Sans.get()
        );
        void Draw(UPtrSDL_Renderer& renderer);
        NoHandle();
        std::list<UPtrSDL_Texture> Init(UPtrSDL_Renderer& renderer);
    private:
        union {
            SDL_Surface* surface;
            SDL_Texture* texture;
        };
};