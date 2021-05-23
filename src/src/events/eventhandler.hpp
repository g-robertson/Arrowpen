#pragma once

#include <memory>

#include "SDL2/SDL.h"

class FullWindow;

class EventHandler {
    public:
        bool Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent);
        bool (*ComplexCallback)(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) = &nonFunction;
        bool (*SDL_QUIT_FUNC)(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) = &nonFunction;
    private:
        static bool nonFunction(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {return true;}
        // TODO: The rest of the events
};