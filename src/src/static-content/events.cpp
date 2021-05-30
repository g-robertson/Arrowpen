#include "events.hpp"
#include "fullwindow.hpp"
#include <iostream>

bool GENERIC_QUIT_FUNC(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {
    return false;
}

bool GENERIC_WINDOWEVENT_FUNC(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {
    if (sdlEvent->window.event == SDL_WINDOWEVENT_RESIZED) {

        fullWindow->screen->actors->ChangeParentDimensions(sdlEvent->window.data1, sdlEvent->window.data2);
    }
    return true;
}