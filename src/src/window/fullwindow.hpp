#pragma once

#include <memory>


#include "screens.hpp"

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"


class EventHandler;
class Graphics;

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
        Static::Screens::ScreenNames screen;
        std::shared_ptr<Graphics> graphics;
        std::shared_ptr<EventHandler> screenEventHandler;
        std::shared_ptr<EventHandler> genericEventHandler;
};