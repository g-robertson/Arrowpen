#pragma once

#include "actor.hpp"
class FloatActor : public Actor {
    public:
        FloatActor(float x, float y, float w, float h);

        virtual void ChangeParentDimensions(int rw, int rh);

        const SDL_Rect* rectg();
        float xg();
        float yg();
        float wg();
        float hg();
        
    protected:
        float x;
        float y;
        float w;
        float h;
        std::shared_ptr<SDL_Rect> rect;
};