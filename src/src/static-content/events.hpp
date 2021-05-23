#pragma once

#include <iostream>
#include <memory>
#include "eventhandler.hpp"

class FullWindow;

namespace {
    bool initialized = false;
    bool QUIT_FUNC(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {return false;}
}

namespace Static {
    namespace Events {
        std::shared_ptr<EventHandler> GenericEventHandler() {
            static std::shared_ptr<EventHandler> __GenericEventHandler;
            if (!initialized) {
                __GenericEventHandler = std::shared_ptr<EventHandler>(new EventHandler);
                __GenericEventHandler->SDL_QUIT_FUNC = QUIT_FUNC;
                initialized = true;
            }
            return __GenericEventHandler;
        }
    };
};