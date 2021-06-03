#pragma once

#include "helpers.hpp"
#include "eventhandler.hpp"
#include "SDL2/SDL.h"

namespace Static {
    namespace Screens {
        class Screen;
    };
};


bool GENERIC_QUIT_FUNC(Static::Screens::Screen* screen, SDL_Event& sdlEvent); 
bool GENERIC_WINDOWEVENT_FUNC(Static::Screens::Screen* screen, SDL_Event& sdlEvent);


namespace Static {
    namespace Events {
        static auto INIT_EVENT = SDL_RegisterEvents(1);

        extern const std::unique_ptr<EventHandler> GenericEventHandler;
    };
};