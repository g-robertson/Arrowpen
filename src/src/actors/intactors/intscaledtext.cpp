#include "fonts.hpp"
#include "intscaledtext.hpp"

IntScaledTextActor::IntScaledTextActor(const char* text, const SDL_Color& textColor, TTF_Font* font) {
    this->surface = UPtrSDL_Surface(TTF_RenderText_Blended(font, text, SDL_Color(textColor)));
    this->rect = std::make_unique<SDL_Rect>(SDL_Rect());
}

IntScaledTextActor::IntScaledTextActor(int x, int y, int w, int h, const char* text, const SDL_Color& textColor, TTF_Font* font) {
    this->surface = UPtrSDL_Surface(TTF_RenderText_Blended(font, text, SDL_Color(textColor)));
    this->rect = std::make_unique<SDL_Rect>(SDL_Rect({x, y, w, h}));
}

void IntScaledTextActor::Draw(UPtrSDL_Renderer& renderer) {
    if (!assignedTexture) {
        this->texture = UPtrSDL_Texture(SDL_CreateTextureFromSurface(renderer.get(), surface.get()));
        this->assignedTexture = true;
    }
    SDL_RenderCopy(renderer.get(), this->texture.get(), NULL, this->rect.get());
}