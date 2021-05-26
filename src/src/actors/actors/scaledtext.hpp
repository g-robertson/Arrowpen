#pragma once
#include <string>

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"

#include "fonts.hpp"
#include "actor.hpp"
#include "color.hpp"

class ScaledTextActor : public Actor {
    public:
        ScaledTextActor(
            int x, int y, int w, int h,
            const char* text, const Color& textColor = Colors::BLACK, TTF_Font* font = Fonts::Sans.get()
        );
        void Draw(SDL_Renderer* renderer);
        NoHandle();
        
    private:
        TTF_Font* font;
        bool assignedTexture = false;
        UPtrSDL_Texture texture;
        std::shared_ptr<SDL_Rect> rect;
};