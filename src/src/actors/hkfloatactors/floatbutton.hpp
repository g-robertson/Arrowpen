#pragma once
#include "floatactor.hpp"
#include "button.hpp"

class FloatButtonActor : public FloatActor, public ButtonActor {
    public:
        FloatButtonActor(
            float x, float y, float w, float h, const char* text,
            float padding = 0.045f,
            float textPadding = 0.09f,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3f,
            TTF_Font* font = Fonts::Sans.get()
        );
        FloatButtonActor(
            float x, float y, float w, float h, const char* text,
            event_callback_t onClickCallback,
            float padding = 0.045f,
            float textPadding = 0.09f,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3f,
            TTF_Font* font = Fonts::Sans.get()
        );

        void ChangeParentDimensions(int rw, int rh);
    private:
        float padding;
        float textPadding;
};