#include <iostream>
#include <chrono>
#include "screens.hpp"
#include "fullwindow.hpp"
#include "sdlhelp.hpp"

FullWindow::FullWindow(
    SDL_Window* window,
    Static::Screens::ScreenNames screen,
    std::shared_ptr<EventHandler> eventHandler
) {
    this->window = UPtrSDL_Window(window);
    this->renderer = UPtrSDL_Renderer(SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED));
    this->screen = screen;
    auto ss = Static::Screens::SelectScreen(screen);
    this->graphics = ss->graphics;
    this->screenEventHandler = ss->eventHandler;
    this->genericEventHandler = eventHandler;
}

void FullWindow::Listen(bool allowSlow) {
    auto sdlEvent = std::shared_ptr<SDL_Event>(new SDL_Event);

    while (SDL_WaitEvent(sdlEvent.get())) {
        this->graphics->Draw(this->renderer.get());
        if (!this->genericEventHandler->Handle(this, sdlEvent) || !this->screenEventHandler->Handle(this, sdlEvent)) {
            return;
        }
    }
}