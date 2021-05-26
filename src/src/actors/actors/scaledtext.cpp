#include "fonts.hpp"
#include "scaledtext.hpp"
#include <iostream>

ScaledTextActor::ScaledTextActor(int x, int y, int w, int h, const char* text, const Color& textColor, TTF_Font* font) {
    this->rect = SharedNewPtr(SDL_Rect, {x, y, w, h});
    this->font = font;
}

void ScaledTextActor::Draw(SDL_Renderer* renderer) {
    if (!assignedTexture) {
        auto surface = TTF_RenderText_Blended(Fonts::Sans.get(), "graphics is my passion", SDL_Color { 0, 0, 0, 255});
        this->texture = UPtrSDL_Texture(SDL_CreateTextureFromSurface(renderer, surface));
        this->assignedTexture = true;
        SDL_FreeSurface(surface);
    }
    SDL_RenderCopy(renderer, this->texture.get(), NULL, this->rect.get());
}