#include "floatscaledtext.hpp"

FloatScaledTextActor::FloatScaledTextActor(float x, float y, float w, float h, const char* text, const SDL_Color& textColor, TTF_Font* font) :
FloatActor(x, y, w, h), ScaledTextActor(text, textColor, font) {}