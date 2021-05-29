#include "colors.hpp"
#include "button.hpp"

ButtonActor::ButtonActor(
    float x, float y, float w, float h, const char* text,
    event_callback_t onClickCallback,
    unsigned int padding,
    unsigned int textPadding,
    const SDL_Color& textColor, 
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
) : FloatActor(x, y, w, h) {
    this->outerRectangleActor = SharedNewPtr(IntRectangleActor, *Colors::Contrast(backgroundColor, outerContrast).get(), this->rect);
    this->innerRectangleActor = SharedNewPtr(IntRectangleActor, backgroundColor);
    this->scaledTextActor = SharedNewPtr(IntScaledTextActor, text, textColor, font);

    this->padding = padding;
    this->textPadding = textPadding;

    this->onClick = onClickCallback;
}

ButtonActor::ButtonActor(
    float x, float y, float w, float h, const char* text, unsigned int padding, unsigned int textPadding,
    const SDL_Color& textColor, const SDL_Color& backgroundColor, float outerContrast,
    TTF_Font* font
) : FloatActor(x, y, w, h) {
    this->outerRectangleActor = SharedNewPtr(IntRectangleActor,*Colors::Contrast(backgroundColor, outerContrast).get(), this->rect);
    this->innerRectangleActor = SharedNewPtr(IntRectangleActor, backgroundColor);
    this->scaledTextActor = SharedNewPtr(IntScaledTextActor, text, textColor, font);

    this->padding = padding;
    this->textPadding = textPadding;
}

void ButtonActor::Draw(SDL_Renderer* renderer) {
    this->outerRectangleActor->Draw(renderer);
    this->innerRectangleActor->Draw(renderer);
    this->scaledTextActor->Draw(renderer);
}

bool ButtonActor::Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {
    switch (sdlEvent->type) {
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            if (sdlEvent->button.button == SDL_BUTTON_LEFT) {
                switch (sdlEvent->button.state) {
                    case SDL_PRESSED:
                        if (!this->pressed && InBounds(sdlEvent->button.x, sdlEvent->button.y, *this->rect.get())) {
                            this->innerRectangleActor->color = Colors::Contrast(*this->innerRectangleActor->color.get(), 1.1);
                            this->outerRectangleActor->color = Colors::Contrast(*this->outerRectangleActor->color.get(), 1.1);
                            this->pressed = true;
                        }
                        break;
                    case SDL_RELEASED:
                        if (this->pressed) {
                            this->innerRectangleActor->color = Colors::Contrast(*this->innerRectangleActor->color.get(), 1 / 1.1);
                            this->outerRectangleActor->color = Colors::Contrast(*this->outerRectangleActor->color.get(), 1 / 1.1);
                            this->pressed = false;
                            if (InBounds(sdlEvent->button.x, sdlEvent->button.y, *this->rect.get())) {
                                return this->onClick(fullWindow, sdlEvent);
                            }
                        }
                        break;
                }
            }
            break;
    }
    return true;
}

void ButtonActor::ChangeParentDimensions(int rw, int rh) {
    // floored to be consistent with the ceil
    this->rect->x = std::floor(this->x * rw);
    this->rect->y = std::floor(this->y * rh);
    // ceiled to avoid 1px missing texture lines
    this->rect->w = std::ceil(this->w * rw);
    this->rect->h = std::ceil(this->h * rh);

    this->innerRectangleActor->rect->x = this->rect->x + this->padding;
    this->innerRectangleActor->rect->y = this->rect->y + this->padding;
    this->innerRectangleActor->rect->w = this->rect->w - (2 * this->padding);
    this->innerRectangleActor->rect->h = this->rect->h - (2 * this->padding);

    this->scaledTextActor->rect->x = this->rect->x + this->textPadding;
    this->scaledTextActor->rect->y = this->rect->y + this->textPadding;
    this->scaledTextActor->rect->w = this->rect->w - (2 * this->textPadding);
    this->scaledTextActor->rect->h = this->rect->h - (2 * this->textPadding);
}