#include <iostream>
#include <chrono>
#include "screens.hpp"
#include "fullwindow.hpp"

FullWindow::FullWindow(SDL_Window* window, Static::Screens::ScreenNames screen, std::shared_ptr<EventHandler> eventHandler) {
    this->window = window;
    this->screen = screen;
    std::shared_ptr<Static::Screens::ScreenSelection> ss = Static::Screens::SelectScreen(screen);
    this->graphics = ss->graphics;
    this->screenEventHandler = ss->eventHandler;
    this->genericEventHandler = eventHandler;
}

void FullWindow::Listen(bool allowSlow) {
    std::shared_ptr<SDL_Event> sdlEvent = std::shared_ptr<SDL_Event>(new SDL_Event);
    //std::weak_ptr<FullWindow> self = std::weak_ptr<FullWindow>(this);
    while (SDL_WaitEvent(sdlEvent.get())) {
        if (!this->genericEventHandler->Handle(this, sdlEvent) || !this->screenEventHandler->Handle(this, sdlEvent)) {
            return;
        }
    }
}