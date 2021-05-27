#pragma once
#include <memory>

#include "events.hpp"
#include "colors.hpp"
#include "rectangle.hpp"
#include "scaledtext.hpp"

class ButtonActor : public Actor {
    public:
        ButtonActor(
            int x, int y, int w, int h, const char* text,
            unsigned int padding = 3,
            unsigned int textPadding = 10,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3,
            TTF_Font* font = Fonts::Sans.get()
        );
        ButtonActor(
            int x, int y, int w, int h, const char* text,
            event_callback_t onClickCallback,
            unsigned int padding = 3,
            unsigned int textPadding = 10,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3,
            TTF_Font* font = Fonts::Sans.get()
        );
        void Draw(SDL_Renderer* renderer);
        bool Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent);
        
        event_callback_t onClick = &noEventCallback;

        bool pressed = false;
        std::shared_ptr<RectangleActor> outerRectangleActor;
        std::shared_ptr<RectangleActor> innerRectangleActor;
        std::shared_ptr<ScaledTextActor> scaledTextActor;
};