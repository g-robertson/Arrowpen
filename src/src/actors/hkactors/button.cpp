#include "colors.hpp"
#include "button.hpp"

ButtonActor::ButtonActor(
    int x, int y, int w, int h, const char* text,
    event_callback_t onClickCallback,
    unsigned int padding,
    unsigned int textPadding,
    const SDL_Color& textColor, 
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
) {
    this->outerRectangleActor = SharedNewPtr(RectangleActor,
        *Colors::Contrast(backgroundColor, outerContrast).get(), x, y, w, h);
    
    this->innerRectangleActor = SharedNewPtr(RectangleActor,
        backgroundColor, x + padding, y + padding, w - (padding * 2), h - (padding * 2));
    
    this->scaledTextActor = SharedNewPtr(ScaledTextActor,
        x + textPadding, y + textPadding, w - (textPadding * 2), h - (textPadding * 2), text, textColor, font);

    this->onClick = onClickCallback;
}

ButtonActor::ButtonActor(
    int x, int y, int w, int h, const char* text, unsigned int padding, unsigned int textPadding,
    const SDL_Color& textColor, const SDL_Color& backgroundColor, float outerContrast,
    TTF_Font* font
) {
    this->outerRectangleActor = SharedNewPtr(RectangleActor,
        *Colors::Contrast(backgroundColor, outerContrast).get(), x, y, w, h);
    
    this->innerRectangleActor = SharedNewPtr(RectangleActor,
        backgroundColor, x + padding, y + padding, w - (padding * 2), h - (padding * 2));
    
    this->scaledTextActor = SharedNewPtr(ScaledTextActor,
        x + textPadding, y + textPadding, w - (textPadding * 2), h - (textPadding * 2), text, textColor, font);
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
                        if (!this->pressed && InBounds(sdlEvent->button.x, sdlEvent->button.y, *this->outerRectangleActor->rect.get())) {
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
                            if (InBounds(sdlEvent->button.x, sdlEvent->button.y, *this->outerRectangleActor->rect.get())) {
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