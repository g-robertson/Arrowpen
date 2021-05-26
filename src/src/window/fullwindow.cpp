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
    this->screen = Static::Screens::SelectScreen(screen);
    this->dynamicActors = SharedNewPtr(ImmutableActorsActor);
    this->globalEventHandler = eventHandler;
}

void FullWindow::Listen(bool allowSlow) {
    auto sdlEvent = std::shared_ptr<SDL_Event>(new SDL_Event);
    while (SDL_WaitEvent(sdlEvent.get())) {
        SDL_SetRenderDrawColor(this->renderer.get(), ExpandColor(this->screen->backgroundColor));
        SDL_RenderClear(this->renderer.get());
        if (
            !this->globalEventHandler->Handle(this, sdlEvent) ||
            !this->screen->eventHandler->Handle(this, sdlEvent) ||
            !this->screen->actors->Handle(this, sdlEvent) ||
            !this->dynamicActors->Handle(this, sdlEvent)
        ) {
            return;
        }
        this->screen->actors->Draw(this->renderer.get());
        this->dynamicActors->Draw(this->renderer.get());
        SDL_RenderPresent(this->renderer.get());
    }
}