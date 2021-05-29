#pragma once

#include <memory>
#include "screens.hpp"

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"


class EventHandler;
class TopActors;

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
        std::shared_ptr<TopActors> dynamicActors;
        std::shared_ptr<EventHandler> globalEventHandler;
};