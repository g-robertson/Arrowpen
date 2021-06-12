#pragma once

#include "actor.hpp"

class RefActor : virtual public Actor {
    public:
        RefActor();
        RefActor(const SDL_Rect* rect);
        RefActor(const std::unique_ptr<SDL_Rect>& rect);

        const SDL_Rect* rectg() {return this->rect;}
    private:
        const SDL_Rect* rect;
};