#include "events.hpp"
#include "fullwindow.hpp"
#include <iostream>

bool GENERIC_QUIT_FUNC(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent) {
    return false;
}

bool GENERIC_WINDOWEVENT_FUNC(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent) {
    if (sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED) {

        screen->actors->ChangeParentDimensions(sdlEvent.window.data1, sdlEvent.window.data2);
    }
    return true;
}