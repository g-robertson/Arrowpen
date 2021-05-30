#pragma once

#include "helpers.hpp"
#include "eventhandler.hpp"
#include "SDL2/SDL.h"


bool GENERIC_QUIT_FUNC(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent); 
bool GENERIC_WINDOWEVENT_FUNC(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent);


namespace Static {
    namespace Events {
        static auto INIT_EVENT = SDL_RegisterEvents(1);

        static auto GenericEventHandler = SharedNewPtr(EventHandler, event_callback_map_t {
            {SDL_QUIT, &GENERIC_QUIT_FUNC},
            {SDL_WINDOWEVENT, &GENERIC_WINDOWEVENT_FUNC}
        });
    };
};