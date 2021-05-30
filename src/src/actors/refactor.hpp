#pragma once

#include "actor.hpp"

class RefActor : public Actor {
    public:
        RefActor();
        RefActor(const std::unique_ptr<SDL_Rect>& rect);
        const std::experimental::observer_ptr<SDL_Rect> rectg();
    protected:
        std::experimental::observer_ptr<SDL_Rect> rect;
};