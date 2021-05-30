#include "helpers.hpp"
#include "floatrectangle.hpp"

#include "SDL2/SDL.h"

// lol
FloatRectangleActor::FloatRectangleActor(const SDL_Color& c, float x, float y, float w, float h, bool filled) :
FloatActor(x, y, w, h),
RectangleActor(c, filled) {}

void FloatRectangleActor::Draw(SDL_Renderer* renderer) {
    this->RDraw(renderer, this->rectg());
}