#pragma once
#include "SDL2/SDL.h"
#include <memory>
#include <vector>

#include "actor.hpp"

class Graphics {
    public:
        Graphics();
        void Draw(SDL_Renderer* renderer);

        std::vector<std::shared_ptr<Actor>> actors;
};