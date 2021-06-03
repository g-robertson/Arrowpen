#pragma once

#include "actor.hpp"

class RefActor : public Actor {
    public:
        RefActor();
        RefActor(const std::unique_ptr<SDL_Rect>& rect);
        const SDL_Rect* rectg();
    protected:
        SDL_Rect* rect;
};