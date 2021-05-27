#pragma once

#include "helpers.hpp"
#include "eventhandler.hpp"
#include "SDL2/SDL.h"

class FullWindow;

namespace {
    bool QUIT_FUNC(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {return false;}
}

namespace Static {
    namespace Events {
        static auto INIT_EVENT = SDL_RegisterEvents(1);

        static auto GenericEventHandler = SharedNewPtr(EventHandler, event_callback_map_t {
            {SDL_QUIT, QUIT_FUNC}
        });
    };
};