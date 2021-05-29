#include "floatactor.hpp"

FloatActor::FloatActor(float x, float y, float w, float h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->rect = SharedNewPtr(SDL_Rect);
}

void FloatActor::ChangeParentDimensions(int rw, int rh) {
    // floored to be consistent with the ceil
    this->rect->x = std::floor(this->x * rw);
    this->rect->y = std::floor(this->y * rh);
    // ceiled to avoid 1px missing texture lines
    this->rect->w = std::ceil(this->w * rw);
    this->rect->h = std::ceil(this->h * rh);
}

const SDL_Rect* FloatActor::rectg() {
    return this->rect.get();
}

const float FloatActor::xg() {
    return this->x;
}

const float FloatActor::yg() {
    return this->y;
}

const float FloatActor::wg() {
    return this->w;
}

const float FloatActor::hg() {
    return this->h;
}