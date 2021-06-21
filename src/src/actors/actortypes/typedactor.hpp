#pragma once
#include "actor.hpp"
#include "owningactor.hpp"
#include "refactor.hpp"
#include "floatactor.hpp"
#include "intactor.hpp"
#include "helpers.hpp"

/*
    Inheriting like this is kinda gross, but it's also the simplest way I could find to be able to template type the actors derived from each actor type
*/

template <class T>
class TypedActor {};

template <>
class TypedActor<RefActor> : virtual public Actor {
    public:
        TypedActor();
        TypedActor(RefActor* actor);
        
        const SDL_Rect* rectg() {return this->actor->rectg();}
    private:
        std::unique_ptr<RefActor, RefActor_Destroy> actor;
};

template <>
class TypedActor<FloatActor> : virtual public Actor {
    public:
        TypedActor();
        TypedActor(FloatActor* actor);
        void ChangeParentDimensions(int rw, int rh);
        float xg() {return this->actor->xg();}
        float yg() {return this->actor->yg();}
        float wg() {return this->actor->wg();}
        float hg() {return this->actor->hg();}

        const SDL_Rect* rectg() {return this->actor->rectg();}
    protected:
        virtual void ChangeParentDimensionsCallback(int, int) {}
    private:
        std::unique_ptr<FloatActor, FloatActor_Destroy> actor;
};

template <>
class TypedActor<IntActor> : virtual public Actor {
    public:
        TypedActor();
        TypedActor(IntActor* actor);
        
        void rects(int x, int y, int w, int h);
        const SDL_Rect* rectg() {return this->actor->rectg();}
    protected:
        virtual void rectsCallback(int, int, int, int) {};
    private:
        std::unique_ptr<IntActor, IntActor_Destroy> actor;
};