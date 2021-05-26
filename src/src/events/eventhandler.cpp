#include <iostream>
#include "eventhandler.hpp"

EventHandler::EventHandler(event_callback_map_t sdlEventCallbacks, event_callback_t complexCallback) {
    this->sdlEventCallbacks = sdlEventCallbacks;
    this->complexCallback = complexCallback;
}

bool EventHandler::Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {
    if (!this->complexCallback(fullWindow, sdlEvent)) {
        return false;
    }
    auto pair = sdlEventCallbacks.find(sdlEvent->type);
    if (pair != sdlEventCallbacks.end() && !pair->second(fullWindow, sdlEvent)) {
        return false;
    }

    return true;
}