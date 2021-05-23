#include <iostream>
#include "eventhandler.hpp"

bool EventHandler::Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {
    #define SEventCallback(event) else if (sdlEvent->type == event && !this->event ## _FUNC(fullWindow, sdlEvent)) return false
    if (!this->ComplexCallback(fullWindow, sdlEvent)) {
        return false;
    }
    SEventCallback(SDL_QUIT);
    return true;
}