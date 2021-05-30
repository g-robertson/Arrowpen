#pragma once

#include <map>
#include <memory>

#include "helpers.hpp"

#include "SDL2/SDL.h"

namespace Static {
    namespace Screens {
        class Screen;
    };
};

class EventHandler {
    public:
        EventHandler(
            event_callback_map_t sdlEventCallbacks = event_callback_map_t(),
            event_callback_t complexCallback = &noEventCallback
        );

        event_callback_t complexCallback;
        event_callback_map_t sdlEventCallbacks;

        bool Handle(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent);
};