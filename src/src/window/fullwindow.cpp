#include <chrono>
#include "screens.hpp"
#include "fullwindow.hpp"
#include "colors.hpp"
#include "sdlhelp.hpp"

FullWindow::FullWindow(
    SDL_Context* context,
    Static::Screens::ScreenNames screen,
    EventHandler* eventHandler
) {
    this->context = context;
    this->screen = Static::Screens::SelectScreen(screen);
    this->globalEventHandler = eventHandler;
}

void FullWindow::Listen(bool allowSlow) {
    int windoww;
    int windowh;
    SDL_GetWindowSize(this->context->window.get(), &windoww, &windowh);
    this->screen->actors->ChangeParentDimensions(windoww, windowh);
    
    SDL_Event sdlEvent;
    while (SDL_WaitEvent(&sdlEvent)) {

        SDL_SetRenderDrawColor(this->context->renderer.get(), ExpandColor(this->screen->backgroundColor));
        SDL_RenderClear(this->context->renderer.get());

        this->screen->actors->FocusHandle(this->screen, sdlEvent);
        if (
            !this->globalEventHandler->Handle(this->screen, sdlEvent) ||
            !this->screen->eventHandler->Handle(this->screen, sdlEvent) ||
            !this->screen->actors->Handle(this->screen, sdlEvent)
        ) {
            return;
        }
        this->screen->actors->Draw(this->context->renderer);
        SDL_RenderPresent(this->context->renderer.get());

        this->screen->actors->UnregisterEvents();
    }
    return;
}