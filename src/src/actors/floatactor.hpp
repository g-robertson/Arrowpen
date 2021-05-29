#pragma once

#include "actor.hpp"
class FloatActor : public Actor {
    public:
        FloatActor(float x, float y, float w, float h);

        virtual void ChangeParentDimensions(int rw, int rh);

        const SDL_Rect* rectg();
        const float xg();
        const float yg();
        const float wg();
        const float hg();
        
    protected:
        float x;
        float y;
        float w;
        float h;
        std::shared_ptr<SDL_Rect> rect;
};