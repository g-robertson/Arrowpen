#include "button.hpp"
#include "screens.hpp"

template <class T>
ButtonActor<T>::ButtonActor(
    T* actor,
    const char* text,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
) : TypedActor<T>(actor) {
    this->outerRectangleActor = std::make_unique<RectangleActor<RefActor>>(RectangleActor<RefActor>(
        new RefActor(this->rectg()),
        Colors::Contrast(backgroundColor, outerContrast)
    ));
    this->innerRectangleActor = std::make_unique<RectangleActor<IntActor>>(RectangleActor<IntActor>(backgroundColor));
    this->scaledTextActor = std::make_unique<ScaledTextActor<IntActor>>(ScaledTextActor<IntActor>(text, textColor, font));
}


template ButtonActor<RefActor>::ButtonActor(
    RefActor* actor,
    const char* text,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font);
template ButtonActor<IntActor>::ButtonActor(
    IntActor* actor,
    const char* text,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
);
ButtonActor<FloatActor>::ButtonActor(
    FloatActor* actor,
    const char* text,
    float padding,
    float textPadding,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
) : TypedActor<FloatActor>(actor) {
    this->padding = padding;
    this->textPadding = textPadding;
    this->outerRectangleActor = std::make_unique<RectangleActor<RefActor>>(RectangleActor<RefActor>(
        new RefActor(this->rectg()),
        Colors::Contrast(backgroundColor, outerContrast)
    ));
    this->innerRectangleActor = std::make_unique<RectangleActor<IntActor>>(RectangleActor<IntActor>(backgroundColor));
    this->scaledTextActor = std::make_unique<ScaledTextActor<IntActor>>(ScaledTextActor<IntActor>(text, textColor, font));
}


template <class T>
ButtonActor<T>::ButtonActor(
    T* actor,
    const char* text,
    event_callback_t onClickCallback,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
) : ButtonActor::ButtonActor(actor, text, textColor, backgroundColor, outerContrast, font) {
    this->onClick = onClickCallback;
}

template ButtonActor<RefActor>::ButtonActor(
    RefActor* actor,
    const char* text,
    event_callback_t onClickCallback,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
);
template ButtonActor<IntActor>::ButtonActor(
    IntActor* actor,
    const char* text,
    event_callback_t onClickCallback,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
);
ButtonActor<FloatActor>::ButtonActor(
    FloatActor* actor,
    const char* text,
    event_callback_t onClickCallback,
    float padding,
    float textPadding,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    float outerContrast,
    TTF_Font* font
) : ButtonActor<FloatActor>::ButtonActor(actor, text, padding, textPadding, textColor, backgroundColor, outerContrast, font) {
    this->onClick = onClickCallback;
}



template <class T>
void ButtonActor<T>::Draw(UPtrSDL_Renderer& renderer) {
    this->outerRectangleActor->Draw(renderer);
    this->innerRectangleActor->Draw(renderer);
    this->scaledTextActor->Draw(renderer);
}

template <class T>
bool ButtonActor<T>::Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent) {
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

template <class T>
std::list<UPtrSDL_Texture> ButtonActor<T>::Init(UPtrSDL_Renderer& renderer) {
    return this->scaledTextActor->Init(renderer);
}

void ButtonActor<FloatActor>::Draw(UPtrSDL_Renderer& renderer) {
    this->outerRectangleActor->Draw(renderer);
    this->innerRectangleActor->Draw(renderer);
    this->scaledTextActor->Draw(renderer);
}

bool ButtonActor<FloatActor>::Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent) {
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

std::list<UPtrSDL_Texture> ButtonActor<FloatActor>::Init(UPtrSDL_Renderer& renderer) {
    return this->scaledTextActor->Init(renderer);
}
void ButtonActor<FloatActor>::ChangeParentDimensionsCallback(int, int) {
    auto mwh = std::min(this->rectg()->w, this->rectg()->h);
    auto mwhPadding = mwh * this->padding;
    auto mwhTextPadding = mwh * this->textPadding;
    
    this->innerRectangleActor->rects(
        this->rectg()->x + std::floor(mwhPadding),
        this->rectg()->y + std::floor(mwhPadding),
        this->rectg()->w - std::floor(mwhPadding * 2),
        this->rectg()->h - std::floor(mwhPadding * 2)
    );

    this->scaledTextActor->rects(
        this->rectg()->x + std::floor(mwhTextPadding),
        this->rectg()->y + std::floor(mwhTextPadding),
        this->rectg()->w - std::floor(mwhTextPadding * 2),
        this->rectg()->h - std::floor(mwhTextPadding * 2)
    );
}