#include "actor.hpp"
#include "events.hpp"
#include "rectangle.hpp"
#include "scaledtext.hpp"


class GenericButtonActor : virtual public Actor {
    public:
        GenericButtonActor(
            RefActor* actor,
            const char* text,
            const SDL_Color& textColor = Colors::DARKTHEME_TEXT,
            const SDL_Color& backgroundColor = Colors::DARKTHEME_BACKGROUND,
            TTF_Font* font = Fonts::Sans.get()
        );
        bool Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent);
        virtual std::list<UPtrSDL_Texture> Init(UPtrSDL_Renderer& renderer);
        
        event_callback_t onClick = &noEventCallback;
        virtual void OnPress() {}
        virtual void OnDepress() {}
    protected:
        std::unique_ptr<RectangleActor<RefActor>> outerRectangleActor;
        std::unique_ptr<ScaledTextActor<IntActor>> scaledTextActor;

    private:
        bool pressed = false;
};