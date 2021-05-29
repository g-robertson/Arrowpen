#pragma once
#include <string>

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"

#include "fonts.hpp"
#include "floatactor.hpp"
#include "colors.hpp"

class ScaledTextActor : public FloatActor {
    public:
        ScaledTextActor(
            float x, float y, float w, float h,
            const char* text, const SDL_Color& textColor = Colors::BLACK, TTF_Font* font = Fonts::Sans.get()
        );
        void Draw(SDL_Renderer* renderer);
        NoHandle();
        
    private:
        SDL_Surface* surface;
        bool assignedTexture = false;
        UPtrSDL_Texture texture;
};