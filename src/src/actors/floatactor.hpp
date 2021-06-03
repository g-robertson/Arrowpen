#pragma once

#include "actor.hpp"

class FloatActor : public Actor {
    public:
        FloatActor();
        FloatActor(float x, float y, float w, float h);
        virtual void ChangeParentDimensions(int rw, int rh);

        float xg();
        float yg();
        float wg();
        float hg();
        const SDL_Rect* rectg();

        virtual ~FloatActor() {};
    protected:
        std::unique_ptr<SDL_Rect> rect;
        float x;
        float y;
        float w;
        float h;
};

struct FloatActor_Destroy {
    void operator() (FloatActor* floatActor) {
        delete floatActor;
    }
};