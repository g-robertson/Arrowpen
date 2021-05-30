#pragma once

#include "helpers.hpp"
#include "eventhandler.hpp"
#include "SDL2/SDL.h"

namespace Static {
    namespace Screens {
        class Screen;
    };
};


bool GENERIC_QUIT_FUNC(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent); 
bool GENERIC_WINDOWEVENT_FUNC(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent);


namespace Static {
    namespace Events {
        static auto INIT_EVENT = SDL_RegisterEvents(1);

        static auto GenericEventHandler = std::make_shared<EventHandler>(EventHandler(event_callback_map_t {
            {SDL_QUIT, &GENERIC_QUIT_FUNC},
            {SDL_WINDOWEVENT, &GENERIC_WINDOWEVENT_FUNC}
        }));
    };
};