#include <iostream>
#include <chrono>
#include "screens.hpp"
#include "fullwindow.hpp"
#include "sdlhelp.hpp"

FullWindow::FullWindow(
    UPtrSDL_Window window,
    Static::Screens::ScreenNames screen,
    std::weak_ptr<EventHandler> eventHandler
) {
    this->window = std::move(window);
    this->renderer = UPtrSDL_Renderer(SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED));
    this->screen = Static::Screens::SelectScreen(screen);
    this->globalEventHandler = eventHandler;
}

void FullWindow::Listen(bool allowSlow) {
    SDL_Event sdlEvent;

    int windoww;
    int windowh;
    SDL_GetWindowSize(this->window.get(), &windoww, &windowh);
    if (auto screen = this->screen.lock()) {
        screen->actors->ChangeParentDimensions(windoww, windowh);
    }

    while (SDL_WaitEvent(&sdlEvent)) {
        if (auto screenLock = this->screen.lock()) {
            if (auto globalEventHandler = this->globalEventHandler.lock()) {
                auto screen = std::experimental::make_observer(screenLock.get());
                
                SDL_SetRenderDrawColor(this->renderer.get(), ExpandColor(screen->backgroundColor));
                SDL_RenderClear(this->renderer.get());

                screen->actors->FocusHandle(screen, sdlEvent);
                if (
                    !globalEventHandler->Handle(screen, sdlEvent) ||
                    !screen->eventHandler->Handle(screen, sdlEvent) ||
                    !screen->actors->Handle(screen, sdlEvent)
                ) {
                    return;
                }
                screen->actors->Draw(this->renderer.get());
                SDL_RenderPresent(this->renderer.get());

                screen->actors->UnregisterEvents();
            }
        } else {
            return;
        }
    }
}