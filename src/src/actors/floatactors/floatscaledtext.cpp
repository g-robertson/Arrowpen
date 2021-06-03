#include "fonts.hpp"
#include "floatscaledtext.hpp"

FloatScaledTextActor::FloatScaledTextActor(float x, float y, float w, float h, const char* text, const SDL_Color& textColor, TTF_Font* font) :
FloatActor(x, y, w, h) {
    this->surface = TTF_RenderText_Blended(font, text, SDL_Color(textColor));
}

void FloatScaledTextActor::Draw(UPtrSDL_Renderer& renderer) {
    SDL_RenderCopy(renderer.get(), this->texture, NULL, this->rect.get());
}

std::list<UPtrSDL_Texture> FloatScaledTextActor::Init(UPtrSDL_Renderer& renderer) {
    auto texture = UPtrSDL_Texture(SDL_CreateTextureFromSurface(renderer.get(), this->surface));
    SDL_FreeSurface(this->surface);
    // actor gets a copy of the texture, and the textures ownership is transferred to the scope of where it was initted
    this->texture = texture.get();
    std::list<UPtrSDL_Texture> list;
    list.push_back(std::move(texture));
    return list;
}