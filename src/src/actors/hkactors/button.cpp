#include "button.hpp"
#include "screens.hpp"

_ButtonActor::_ButtonActor(RefActor* actor, const char* text, const SDL_Color& textColor, const SDL_Color& backgroundColor, TTF_Font* font, float innerContrast) :
GenericButtonActor(actor, text, textColor, *Colors::Contrast(backgroundColor, innerContrast), font) {
    this->innerContrast = innerContrast;
}

ButtonActor<FloatActor>::ButtonActor(
    FloatActor* actor,
    const char* text,
    float padding,
    float textPadding,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    TTF_Font* font,
    float innerContrast
) : TypedActor<FloatActor>(actor), _ButtonActor(new RefActor(actor->rectg()), text, textColor, backgroundColor, font, innerContrast) {
    this->depressedColor = std::make_unique<SDL_Color>(backgroundColor);
    this->padding = padding;
    this->textPadding = textPadding;
    this->innerRectangleActor = std::make_unique<RectangleActor<IntActor>>(RectangleActor<IntActor>(*this->depressedColor.get()));
}

ButtonActor<FloatActor>::ButtonActor(
    FloatActor* actor,
    const char* text,
    event_callback_t onClickCallback,
    float padding,
    float textPadding,
    const SDL_Color& textColor,
    const SDL_Color& backgroundColor,
    TTF_Font* font,
    float innerContrast
) : ButtonActor<FloatActor>::ButtonActor(actor, text, padding, textPadding, textColor, backgroundColor, font, innerContrast) {
    this->onClick = onClickCallback;
}

void _ButtonActor::OnPress() {
    this->outerRectangleActor->color.release();
    this->innerRectangleActor->color.release();
    this->outerRectangleActor->color = Colors::Contrast(*Colors::Contrast(*this->depressedColor, this->innerContrast), 1.1);
    this->innerRectangleActor->color = Colors::Contrast(*this->depressedColor, 1.1);
}

void _ButtonActor::OnDepress() {
    this->outerRectangleActor->color.release();
    this->innerRectangleActor->color.release();
    this->outerRectangleActor->color = Colors::Contrast(*this->depressedColor, this->innerContrast);
    this->innerRectangleActor->color = std::make_unique<SDL_Color>(*this->depressedColor);
}

void _ButtonActor::Draw(UPtrSDL_Renderer& renderer) {
    this->outerRectangleActor->Draw(renderer);
    this->innerRectangleActor->Draw(renderer);
    this->scaledTextActor->Draw(renderer);
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