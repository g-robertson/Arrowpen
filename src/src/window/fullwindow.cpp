#include <iostream>
#include <chrono>
#include "screens.hpp"
#include "fullwindow.hpp"

#include "sdlhelp.hpp"

FullWindow::FullWindow(
    std::unique_ptr<SDL_Window, _SDL_DestroyWindow> window,
    Static::Screens::ScreenNames screen,
    std::shared_ptr<EventHandler> eventHandler
) {
    this->window = std::move(window);
    this->screen = screen;
    auto ss = Static::Screens::SelectScreen(screen);
    this->graphics = ss->graphics;
    this->screenEventHandler = ss->eventHandler;
    this->genericEventHandler = eventHandler;
}

void FullWindow::Listen(bool allowSlow) {
    auto sdlEvent = std::shared_ptr<SDL_Event>(new SDL_Event);

    while (SDL_WaitEvent(sdlEvent.get())) {
        if (!this->genericEventHandler->Handle(this, sdlEvent) || !this->screenEventHandler->Handle(this, sdlEvent)) {
            return;
        }
    }
}