#include <memory>

#include "helpers.hpp"

#include "init.hpp"
#include "events.hpp"
#include "screens.hpp"
#include "fullwindow.hpp"
#include "events.hpp"

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"

FullWindow* Init::Init() {
    auto screen = Static::Screens::ScreenNames::TEST_SCREEN;
    auto fullWindow = new FullWindow(
        SDL_CreateWindow("Arrowpen", 200, 200, 1000, 500, SDL_WINDOW_RESIZABLE),
        screen,
        Static::Events::GenericEventHandler
    );
    SDL_Event initEvent;
    initEvent.type = Static::Events::INIT_EVENT;
    SDL_PushEvent(&initEvent);
    return fullWindow;
}