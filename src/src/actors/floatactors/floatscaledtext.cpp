#include "fonts.hpp"
#include "floatscaledtext.hpp"


ScaledTextActor::ScaledTextActor(float x, float y, float w, float h, const char* text, const SDL_Color& textColor, TTF_Font* font) :
FloatActor(x, y, w, h) {
    this->surface = UPtrSDL_Surface(TTF_RenderText_Blended(font, text, SDL_Color(textColor)));
}

void ScaledTextActor::Draw(SDL_Renderer* renderer) {
    if (!assignedTexture) {
        this->texture = UPtrSDL_Texture(SDL_CreateTextureFromSurface(renderer, this->surface.get()));
        this->assignedTexture = true;
    }
    SDL_RenderCopy(renderer, this->texture.get(), NULL, this->rect.get());
}