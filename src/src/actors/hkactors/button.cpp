#include "button.hpp"
#include "screens.hpp"

ButtonActor::ButtonActor(const char* text, const SDL_Color& textColor, const SDL_Color& backgroundColor, float outerContrast, TTF_Font* font) {
    this->outerRectangleActor = std::make_unique<RefRectangleActor>(RefRectangleActor(Colors::Contrast(backgroundColor, outerContrast), this->rect));
    this->innerRectangleActor = std::make_unique<IntRectangleActor>(IntRectangleActor(backgroundColor));
    this->scaledTextActor = std::make_unique<IntScaledTextActor>(IntScaledTextActor(text, textColor, font));
}

ButtonActor::ButtonActor(const char* text, event_callback_t onClickCallback,
const SDL_Color& textColor, const SDL_Color& backgroundColor, float outerContrast, TTF_Font* font) :
ButtonActor::ButtonActor(text, textColor, backgroundColor, outerContrast, font) {
    this->onClick = onClickCallback;
}

void ButtonActor::Draw(UPtrSDL_Renderer& renderer) {
    this->outerRectangleActor->Draw(renderer);
    this->innerRectangleActor->Draw(renderer);
    this->scaledTextActor->Draw(renderer);
}

bool ButtonActor::Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent) {
    switch (sdlEvent.type) {
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            if (sdlEvent.button.button == SDL_BUTTON_LEFT) {
                switch (sdlEvent.button.state) {
                    case SDL_PRESSED:
                        if (!this->pressed && screen->actors->FocusedActor() == this) {
                            Colors::Contrast(this->innerRectangleActor->color, 1.1);
                            Colors::Contrast(this->outerRectangleActor->color, 1.1);
                            this->pressed = true;
                        }
                        break;
                    case SDL_RELEASED:
                        if (this->pressed) {
                            Colors::Contrast(this->innerRectangleActor->color, 1 / 1.1);
                            Colors::Contrast(this->outerRectangleActor->color, 1 / 1.1);
                            this->pressed = false;
                            if (InBounds(sdlEvent.button.x, sdlEvent.button.y, *this->rectg())) {
                                return this->onClick(screen, sdlEvent);
                            }
                        }
                        break;
                }
            }
            break;
    }
    return true;
}

std::list<UPtrSDL_Texture> ButtonActor::Init(UPtrSDL_Renderer& renderer) {
    return this->scaledTextActor->Init(renderer);
}