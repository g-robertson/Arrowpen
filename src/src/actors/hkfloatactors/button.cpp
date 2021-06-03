#include "colors.hpp"
#include "button.hpp"
#include "fullwindow.hpp"

FloatButtonActor::FloatButtonActor(
    float x, float y, float w, float h, const char* text, float padding, float textPadding,
    const SDL_Color& textColor, const SDL_Color& backgroundColor, float outerContrast,
    TTF_Font* font
) : FloatActor(x, y, w, h) {
    this->outerRectangleActor = std::make_unique<RefRectangleActor>(RefRectangleActor(Colors::Contrast(backgroundColor, outerContrast), this->rect));
    this->innerRectangleActor = std::make_unique<IntRectangleActor>(IntRectangleActor(backgroundColor));
    this->scaledTextActor = std::make_unique<IntScaledTextActor>(IntScaledTextActor(text, textColor, font));

    this->padding = padding;
    this->textPadding = textPadding;
}

FloatButtonActor::FloatButtonActor(
    float x, float y, float w, float h, const char* text,
    event_callback_t onClickCallback,
    float padding,
    float textPadding,
    const SDL_Color& textColor, 
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
) :
FloatButtonActor(x, y, w, h, text, padding, textPadding, textColor, backgroundColor, outerContrast, font) {
    this->onClick = onClickCallback;
}

void FloatButtonActor::Draw(UPtrSDL_Renderer& renderer) {
    this->outerRectangleActor->Draw(renderer);
    this->innerRectangleActor->Draw(renderer);
    this->scaledTextActor->Draw(renderer);
}

bool FloatButtonActor::Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent) {
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
                            if (InBounds(sdlEvent.button.x, sdlEvent.button.y, *this->rect.get())) {
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

std::list<UPtrSDL_Texture> FloatButtonActor::Init(UPtrSDL_Renderer& renderer) {
    return this->scaledTextActor->Init(renderer);
}

void FloatButtonActor::ChangeParentDimensions(int rw, int rh) {
    // floored to be consistent with the ceil
    this->rect->x = std::floor(this->x * rw);
    this->rect->y = std::floor(this->y * rh);
    // ceiled to avoid 1px missing texture lines
    this->rect->w = std::ceil(this->w * rw);
    this->rect->h = std::ceil(this->h * rh);

    auto mwh = std::min(this->rect->w, this->rect->h);
    auto mwhPadding = mwh * this->padding;
    auto mwhTextPadding = mwh * this->textPadding;

    this->innerRectangleActor->rect->x = this->rect->x + std::floor(mwhPadding);
    this->innerRectangleActor->rect->y = this->rect->y + std::floor(mwhPadding);
    this->innerRectangleActor->rect->w = this->rect->w - std::floor(mwhPadding * 2);
    this->innerRectangleActor->rect->h = this->rect->h - std::floor(mwhPadding * 2);
    
    this->scaledTextActor->rect->x = this->rect->x + std::floor(mwhTextPadding);
    this->scaledTextActor->rect->y = this->rect->y + std::floor(mwhTextPadding);
    this->scaledTextActor->rect->w = this->rect->w - std::floor(mwhTextPadding * 2);
    this->scaledTextActor->rect->h = this->rect->h - std::floor(mwhTextPadding * 2);
}