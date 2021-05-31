#pragma once
#include <string>

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"

#include "fonts.hpp"
#include "intactor.hpp"
#include "colors.hpp"

class IntScaledTextActor : public IntActor {
    public:
        IntScaledTextActor(const char* text, const SDL_Color& textColor, TTF_Font* font);
        IntScaledTextActor(
            int x, int y, int w, int h,
            const char* text, const SDL_Color& textColor = Colors::BLACK, TTF_Font* font = Fonts::Sans.get()
        );

        void Draw(SDL_Renderer* renderer);
        NoHandle();

    private:
        UPtrSDL_Surface surface;
        bool assignedTexture = false;
        UPtrSDL_Texture texture;
};