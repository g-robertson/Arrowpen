#pragma once
#include "owningactor.hpp"

class FloatActor : virtual public OwningActor {
    public:
        FloatActor();
        FloatActor(float x, float y, float w, float h);
        virtual ~FloatActor() {}

        void ChangeParentDimensions(int rw, int rh);

        float xg() {return this->x;}
        float yg() {return this->y;}
        float wg() {return this->w;}
        float hg() {return this->h;}
    private:
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