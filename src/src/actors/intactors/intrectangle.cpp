#include "intrectangle.hpp"


IntRectangleActor::IntRectangleActor(const SDL_Color& c, bool filled) :
IntActor(), RectangleActor(c, filled) {}

IntRectangleActor::IntRectangleActor(const SDL_Color& c, SDL_Rect& rect, bool filled) :
IntActor(rect), RectangleActor(c, filled) {}

IntRectangleActor::IntRectangleActor(const SDL_Color& c, int x, int y, int w, int h, bool filled) :
IntActor(x, y, w, h), RectangleActor(c, filled) {}