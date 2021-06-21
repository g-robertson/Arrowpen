#include "floatactor.hpp"
#include "typedactor.hpp"

FloatActor::FloatActor() {
    this->rect = std::make_unique<SDL_Rect>(SDL_Rect());
}

FloatActor::FloatActor(float x, float y, float w, float h) :
FloatActor::FloatActor() {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void TypedActor<FloatActor>::ChangeParentDimensions(int rw, int rh) {
    this->actor->ChangeParentDimensions(rw, rh);
    this->ChangeParentDimensionsCallback(rw, rh);
}

void FloatActor::ChangeParentDimensions(int rw, int rh) {
    // floored to be consistent with the ceil
    this->rect->x = std::floor(this->x * rw);
    this->rect->y = std::floor(this->y * rh);
    // ceiled to avoid 1px missing texture lines
    this->rect->w = std::ceil(this->w * rw);
    this->rect->h = std::ceil(this->h * rh);
}