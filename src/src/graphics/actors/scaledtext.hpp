#pragma once
#include <string>

#include "SDL2/SDL.h"

#include "actor.hpp"
#include "color.hpp"

class ScaledTextActor : public Actor {
    public:
        ScaledTextActor(int x, int y, int w, int h, std::string text, const Color& textColor = Colors::BLACK, const Color& backgroundColor = Colors::TRANSPARENT);
        void Draw(SDL_Renderer* renderer);
};