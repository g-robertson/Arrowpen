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
            std::unique_ptr<SDL_Context> context,
            Static::Screens::ScreenNames screen,
            EventHandler* eventHandler
        );
        void Listen(bool allowSlow = false);
        std::unique_ptr<SDL_Context> context;
        Static::Screens::Screen* screen;
        EventHandler* globalEventHandler;
};