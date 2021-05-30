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
            UPtrSDL_Window window,
            Static::Screens::ScreenNames screen,
            std::weak_ptr<EventHandler> eventHandler
        );
        void Listen(bool allowSlow = false);

        UPtrSDL_Window window;
        UPtrSDL_Renderer renderer;
        std::weak_ptr<Static::Screens::Screen> screen;
        std::weak_ptr<EventHandler> globalEventHandler;
};