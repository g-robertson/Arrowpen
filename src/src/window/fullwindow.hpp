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
            SDL_Context* context,
            Static::Screens::ScreenNames screen,
            EventHandler* eventHandler
        );
        void Listen(bool allowSlow = false);
        SDL_Context* context;
        Static::Screens::Screen* screen;
        EventHandler* globalEventHandler;
};