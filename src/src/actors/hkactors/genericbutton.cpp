#include "genericbutton.hpp"
#include "screens.hpp"

GenericButtonActor::GenericButtonActor(RefActor* actor, const char* text, const SDL_Color& textColor, const SDL_Color& backgroundColor, TTF_Font* font) {
    this->outerRectangleActor = std::make_unique<RectangleActor<RefActor>>(RectangleActor<RefActor>(actor, backgroundColor));
    this->scaledTextActor = std::make_unique<ScaledTextActor<IntActor>>(ScaledTextActor<IntActor>(text, textColor, font));
}

bool GenericButtonActor::Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent) {
    switch (sdlEvent.type) {
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            if (sdlEvent.button.button == SDL_BUTTON_LEFT) {
                switch (sdlEvent.button.state) {
                    case SDL_PRESSED:
                        if (!this->pressed && screen->actors->FocusedActor() == this) {
                            this->pressed = true;
                            this->OnPress();
                        }
                        break;
                    case SDL_RELEASED:
                        if (this->pressed) {
                            this->pressed = false;
                            this->OnDepress();
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

std::list<UPtrSDL_Texture> GenericButtonActor::Init(UPtrSDL_Renderer& renderer) {
    return this->scaledTextActor->Init(renderer);
}