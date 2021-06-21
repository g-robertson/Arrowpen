#pragma once

#include "events.hpp"
#include "colors.hpp"
#include "typedactor.hpp"
#include "rectangle.hpp"
#include "scaledtext.hpp"

template <class T>
class ButtonActor : virtual public TypedActor<T> {
    public:
        ButtonActor(
            T* actor,
            const char* text,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3f,
            TTF_Font* font = Fonts::Sans.get()
        );
        ButtonActor(
            T* actor,
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
        std::unique_ptr<RectangleActor<RefActor>> outerRectangleActor;
        std::unique_ptr<RectangleActor<IntActor>> innerRectangleActor;
        std::unique_ptr<ScaledTextActor<IntActor>> scaledTextActor;

    private:
        bool pressed = false;
};

template <>
class ButtonActor<FloatActor> : virtual public TypedActor<FloatActor> {
    public:
        ButtonActor(
            FloatActor* actor,
            const char* text,
            float padding = 0.045f,
            float textPadding = 0.09f,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            float outerContrast = 1.3f,
            TTF_Font* font = Fonts::Sans.get()
        );
        ButtonActor(
            FloatActor* actor,
            const char* text,
            event_callback_t onClickCallback,
            float padding = 0.045f,
            float textPadding = 0.09f,
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
        std::unique_ptr<RectangleActor<RefActor>> outerRectangleActor;
        std::unique_ptr<RectangleActor<IntActor>> innerRectangleActor;
        std::unique_ptr<ScaledTextActor<IntActor>> scaledTextActor;

        void ChangeParentDimensionsCallback(int rw, int rh);

    private:
        bool pressed = false;
        float padding;
        float textPadding;
};