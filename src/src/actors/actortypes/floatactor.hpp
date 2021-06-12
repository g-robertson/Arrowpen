#pragma once

#include "owningactor.hpp"

class FloatActor : virtual public OwningActor {
    public:
        FloatActor();
        FloatActor(float x, float y, float w, float h);
        
        const SDL_Rect* rectg() {return this->rect.get();}

        virtual void ChangeParentDimensions(int rw, int rh);

        float xg();
        float yg();
        float wg();
        float hg();

        virtual ~FloatActor() {};
    protected:
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