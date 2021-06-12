#include "floatrectangle.hpp"

// lol
FloatRectangleActor::FloatRectangleActor(const SDL_Color& c, float x, float y, float w, float h, bool filled) :
FloatActor(x, y, w, h),
RectangleActor(c, filled) {}