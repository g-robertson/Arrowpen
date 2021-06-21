#include "scaledtext.hpp"
template <class T>
ScaledTextActor<T>::ScaledTextActor(const char* text, const SDL_Color& textColor, TTF_Font* font)  {
    this->surface = TTF_RenderText_Blended(font, text, SDL_Color(textColor));
}

template <class T>
ScaledTextActor<T>::ScaledTextActor(T* actor, const char* text, const SDL_Color& textColor, TTF_Font* font) :
TypedActor<T>(actor) {
    this->surface = TTF_RenderText_Blended(font, text, SDL_Color(textColor));
}

TemplateAllActorsAndNone(ScaledTextActor, const char* text, const SDL_Color& textColor, TTF_Font* font);

template <class T>
void ScaledTextActor<T>::Draw(UPtrSDL_Renderer& renderer) {
    SDL_RenderCopy(renderer.get(), this->texture, NULL, this->rectg());
}

template <class T>
std::list<UPtrSDL_Texture> ScaledTextActor<T>::Init(UPtrSDL_Renderer& renderer) {
    auto texture = UPtrSDL_Texture(SDL_CreateTextureFromSurface(renderer.get(), this->surface));
    SDL_FreeSurface(this->surface);
    // actor gets a copy of the texture, and the textures ownership is transferred to the scope of where it was initted
    this->texture = texture.get();
    std::list<UPtrSDL_Texture> list;
    list.push_back(std::move(texture));
    return list;
}
