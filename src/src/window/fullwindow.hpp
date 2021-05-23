#pragma once

#include <memory>

#include "SDL2/SDL.h"

#include "screens.hpp"

class EventHandler;
class Graphics;

class FullWindow {
    public:
        FullWindow(SDL_Window* window, Static::Screens::ScreenNames screen, std::shared_ptr<EventHandler> eventHandler);
        void Listen(bool allowSlow = false);

        SDL_Window* window;
        Static::Screens::ScreenNames screen;
        std::shared_ptr<Graphics> graphics;
        std::shared_ptr<EventHandler> screenEventHandler;
        std::shared_ptr<EventHandler> genericEventHandler;
};