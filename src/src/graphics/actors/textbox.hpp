#pragma once
#include <string>

#include "SDL2/SDL.h"

#include "actor.hpp"
#include "color.hpp"

class TextboxActor : public Actor {
    public:
        TextboxActor(std::string text, int16_t x, int16_t y, uint16_t w, uint16_t h, Color textColor, Color backgroundColor);
        void Draw(SDL_Renderer* renderer);
};