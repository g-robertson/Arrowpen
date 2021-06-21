#pragma once

#include "owningactor.hpp"

class IntActor : virtual public OwningActor {
    public:
        IntActor();
        IntActor(const SDL_Rect& rect);
        IntActor(std::unique_ptr<SDL_Rect> rect);
        IntActor(int x, int y, int w, int h);
        virtual ~IntActor() {}

        void rects(int x, int y, int w, int h);
};

struct IntActor_Destroy {
    void operator() (IntActor* intActor) {
        delete intActor;
    }
};