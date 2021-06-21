#pragma once
#include "SDL2/SDL.h"
#include <memory>

class RefActor {
    public:
        RefActor();
        RefActor(const SDL_Rect* rect);
        RefActor(const std::unique_ptr<SDL_Rect>& rect);
        virtual ~RefActor() {}

        const SDL_Rect* rectg() {return this->rect;}
    protected:
        const SDL_Rect* rect;
};

struct RefActor_Destroy {
    void operator() (RefActor* refActor) {
        delete refActor;
    }
};