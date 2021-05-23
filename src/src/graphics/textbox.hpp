#pragma once
#include <string>

#include "SDL2/SDL.h"

#include "color.hpp"

class TextboxActor {
    public:
        TextboxActor(std::string text, uint8_t x, uint8_t y, uint8_t w, uint8_t h, Color textColor, Color backgroundColor);
    
        void Draw(SDL_Window* window);
};