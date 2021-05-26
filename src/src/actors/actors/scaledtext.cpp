#include "fonts.hpp"
#include "scaledtext.hpp"
#include <iostream>

ScaledTextActor::ScaledTextActor(int x, int y, int w, int h, const char* text, const SDL_Color& textColor, TTF_Font* font) {
    this->rect = SharedNewPtr(SDL_Rect, {x, y, w, h});
    this->surface = TTF_RenderText_Blended(font, text, SDL_Color(textColor));
}

void ScaledTextActor::Draw(SDL_Renderer* renderer) {
    if (!assignedTexture) {
        this->texture = UPtrSDL_Texture(SDL_CreateTextureFromSurface(renderer, surface));
        this->assignedTexture = true;
        SDL_FreeSurface(this->surface);
    }
    SDL_RenderCopy(renderer, this->texture.get(), NULL, this->rect.get());
}