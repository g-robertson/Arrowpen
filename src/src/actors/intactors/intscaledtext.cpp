#include "intscaledtext.hpp"

IntScaledTextActor::IntScaledTextActor(const char* text, const SDL_Color& textColor, TTF_Font* font) :
IntActor(), ScaledTextActor(text, textColor, font) {}

IntScaledTextActor::IntScaledTextActor(int x, int y, int w, int h, const char* text, const SDL_Color& textColor, TTF_Font* font) :
IntActor(x, y, w, h), ScaledTextActor(text, textColor, font) {}