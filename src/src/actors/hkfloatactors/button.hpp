#pragma once
#include <memory>

#include "floatactor.hpp"
#include "events.hpp"
#include "colors.hpp"
#include "intrectangle.hpp"
#include "intscaledtext.hpp"

class ButtonActor : public FloatActor {
    public:
        ButtonActor(
            float x, float y, float w, float h, const char* text,
            float padding = 0.045,
            float textPadding = 0.09,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3,
            TTF_Font* font = Fonts::Sans.get()
        );
        ButtonActor(
            float x, float y, float w, float h, const char* text,
            event_callback_t onClickCallback,
            float padding = 0.045,
            float textPadding = 0.09,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3,
            TTF_Font* font = Fonts::Sans.get()
        );
        void Draw(SDL_Renderer* renderer);
        bool Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent);
        
        event_callback_t onClick = &noEventCallback;

        void ChangeParentDimensions(int rw, int rh);
    private:
        float padding;
        float textPadding;
        bool pressed = false;
        std::shared_ptr<IntRectangleActor> outerRectangleActor;
        std::shared_ptr<IntRectangleActor> innerRectangleActor;
        std::shared_ptr<IntScaledTextActor> scaledTextActor;
};