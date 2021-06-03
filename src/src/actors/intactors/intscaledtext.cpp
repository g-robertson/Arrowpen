#include "fonts.hpp"
#include "intscaledtext.hpp"

IntScaledTextActor::IntScaledTextActor(const char* text, const SDL_Color& textColor, TTF_Font* font) :
IntActor(SDL_Rect()) {
    this->surface = TTF_RenderText_Blended(font, text, textColor);
}

IntScaledTextActor::IntScaledTextActor(int x, int y, int w, int h, const char* text, const SDL_Color& textColor, TTF_Font* font) :
IntActor(x, y, w, h) {
    this->surface = TTF_RenderText_Blended(font, text, textColor);
}

void IntScaledTextActor::Draw(UPtrSDL_Renderer& renderer) {
    SDL_RenderCopy(renderer.get(), this->texture, NULL, this->rect.get());
}

std::list<UPtrSDL_Texture> IntScaledTextActor::Init(UPtrSDL_Renderer& renderer) {
    auto texture = UPtrSDL_Texture(SDL_CreateTextureFromSurface(renderer.get(), this->surface));
    SDL_FreeSurface(this->surface);
    // actor gets a copy of the texture, and the textures ownership is transferred to the scope of where it was initted
    this->texture = texture.get();
    std::list<UPtrSDL_Texture> list;
    list.push_back(std::move(texture));
    return list;
}