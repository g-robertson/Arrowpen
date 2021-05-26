#pragma once
#include "actor.hpp"

class LineActor : public Actor {
    public:
        LineActor();
        void Draw(SDL_Renderer* renderer);
        NoHandle();
};