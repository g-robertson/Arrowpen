#pragma once

#include "events.hpp"
#include "colors.hpp"
#include "genericbutton.hpp"
#include "typedactor.hpp"

class _ButtonActor : public GenericButtonActor {
    public:
        _ButtonActor(
            RefActor* actor,
            const char* text,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT,
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            TTF_Font* font = Fonts::Sans.get(),
            float innerContrast = 1.3f
        );
        
        void Draw(UPtrSDL_Renderer& renderer);
        
        event_callback_t onClick = &noEventCallback;

        void OnPress();
        void OnDepress();
    protected:
        std::unique_ptr<SDL_Color> depressedColor;
        float innerContrast;
        std::unique_ptr<RectangleActor<IntActor>> innerRectangleActor;
};

// this actor type is too non-generic to be implemented with simple templating
template <class T>
class ButtonActor : virtual public TypedActor<T>, public _ButtonActor {};

// basically just here to say these cases aren't implemented
template <>
class ButtonActor<IntActor> : virtual public TypedActor<IntActor>, public _ButtonActor {};
template <>
class ButtonActor<RefActor> : virtual public TypedActor<RefActor>, public _ButtonActor {};

template <>
class ButtonActor<FloatActor> : virtual public TypedActor<FloatActor>, public _ButtonActor {
    public:
        ButtonActor(
            FloatActor* actor,
            const char* text,
            float padding = 0.045f,
            float textPadding = 0.09f,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            TTF_Font* font = Fonts::Sans.get(),
            float innerContrast = 1.3f
        );
        ButtonActor(
            FloatActor* actor,
            const char* text,
            event_callback_t onClickCallback,
            float padding = 0.045f,
            float textPadding = 0.09f,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT, 
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            TTF_Font* font = Fonts::Sans.get(),
            float innerContrast = 1.3f
        );

    protected:
        void ChangeParentDimensionsCallback(int rw, int rh);
        float padding;
        float textPadding;
};