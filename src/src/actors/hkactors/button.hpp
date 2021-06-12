#pragma once

#include "owningactor.hpp"
#include "events.hpp"
#include "colors.hpp"
#include "refrectangle.hpp"
#include "intrectangle.hpp"
#include "intscaledtext.hpp"

class ButtonActor : virtual public OwningActor {
    public:
        ButtonActor(
            const char* text,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3f,
            TTF_Font* font = Fonts::Sans.get()
        );
        ButtonActor(
            const char* text,
            event_callback_t onClickCallback,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3f,
            TTF_Font* font = Fonts::Sans.get()
        );

        void Draw(UPtrSDL_Renderer& renderer);
        bool Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent);
        std::list<UPtrSDL_Texture> Init(UPtrSDL_Renderer& renderer);
        
        event_callback_t onClick = &noEventCallback;

    protected:
        std::unique_ptr<RefRectangleActor> outerRectangleActor;
        std::unique_ptr<IntRectangleActor> innerRectangleActor;
        std::unique_ptr<IntScaledTextActor> scaledTextActor;

    private:
        bool pressed = false;
};