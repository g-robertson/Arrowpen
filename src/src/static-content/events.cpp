#include "events.hpp"
#include "fullwindow.hpp"

bool GENERIC_QUIT_FUNC(Static::Screens::Screen*, SDL_Event&) {
    return false;
}

bool GENERIC_WINDOWEVENT_FUNC(Static::Screens::Screen* screen, SDL_Event& sdlEvent) {
    if (sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED) {
        screen->actors->ChangeParentDimensions(sdlEvent.window.data1, sdlEvent.window.data2);
    }
    return true;
}

const std::unique_ptr<EventHandler> Static::Events::GenericEventHandler = std::make_unique<EventHandler>(EventHandler(event_callback_map_t {
    {SDL_QUIT, &GENERIC_QUIT_FUNC},
    {SDL_WINDOWEVENT, &GENERIC_WINDOWEVENT_FUNC}
}));