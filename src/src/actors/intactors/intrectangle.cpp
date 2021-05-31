#include "helpers.hpp"
#include "intrectangle.hpp"

#include "SDL2/SDL.h"

IntRectangleActor::IntRectangleActor(const SDL_Color& c, bool filled) :
RectangleActor(c, filled) {}

IntRectangleActor::IntRectangleActor(const SDL_Color& c, SDL_Rect& rect, bool filled) :
RectangleActor(c, filled), IntActor(rect) {}

IntRectangleActor::IntRectangleActor(const SDL_Color& c, int x, int y, int w, int h, bool filled) :
RectangleActor(c, filled), IntActor(x, y, w, h) {}

void IntRectangleActor::Draw(UPtrSDL_Renderer& renderer) {
    this->RDraw(renderer, this->rectg());
}