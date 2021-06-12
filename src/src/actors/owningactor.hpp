#pragma once
#include "actor.hpp"

class OwningActor : virtual public Actor {
    public:
        const SDL_Rect* rectg() {return this->rect.get();}
    
    protected:
        std::unique_ptr<SDL_Rect> rect;
};