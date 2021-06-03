#include "eventhandler.hpp"

EventHandler::EventHandler(event_callback_map_t sdlEventCallbacks, event_callback_t complexCallback) {
    this->sdlEventCallbacks = sdlEventCallbacks;
    this->complexCallback = complexCallback;
}

bool EventHandler::Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent) {
    if (!this->complexCallback(screen, sdlEvent)) {
        return false;
    }
    auto pair = sdlEventCallbacks.find(sdlEvent.type);
    if (pair != sdlEventCallbacks.end() && !pair->second(screen, sdlEvent)) {
        return false;
    }

    return true;
}