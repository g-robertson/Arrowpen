#pragma once

#include <memory>
#include "screens.hpp"

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"


class EventHandler;
class ImmutableActorsActor;

class FullWindow {
    public:
        FullWindow(
            SDL_Window* window,
            Static::Screens::ScreenNames screen,
            std::shared_ptr<EventHandler> eventHandler
        );
        void Listen(bool allowSlow = false);

        UPtrSDL_Window window;
        UPtrSDL_Renderer renderer;
        std::shared_ptr<Static::Screens::Screen> screen;
        std::shared_ptr<ImmutableActorsActor> dynamicActors;
        std::shared_ptr<EventHandler> globalEventHandler;
};