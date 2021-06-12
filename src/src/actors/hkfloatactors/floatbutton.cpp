#include "floatbutton.hpp"

FloatButtonActor::FloatButtonActor(
    float x, float y, float w, float h, const char* text, float padding, float textPadding,
    const SDL_Color& textColor, const SDL_Color& backgroundColor, float outerContrast,
    TTF_Font* font
) :
FloatActor(x, y, w, h),
ButtonActor(text, textColor, backgroundColor, outerContrast, font) {
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
FloatActor(x, y, w, h),
ButtonActor(text, onClickCallback, textColor, backgroundColor, outerContrast, font) {
    this->padding = padding;
    this->textPadding = textPadding;
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

    this->innerRectangleActor->rects(
        this->rect->x + std::floor(mwhPadding),
        this->rect->y + std::floor(mwhPadding),
        this->rect->w - std::floor(mwhPadding * 2),
        this->rect->h - std::floor(mwhPadding * 2)
    );

    this->scaledTextActor->rects(
        this->rect->x + std::floor(mwhTextPadding),
        this->rect->y + std::floor(mwhTextPadding),
        this->rect->w - std::floor(mwhTextPadding * 2),
        this->rect->h - std::floor(mwhTextPadding * 2)
    );
}