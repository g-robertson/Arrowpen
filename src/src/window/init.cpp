#include <memory>

#include "init.hpp"
#include "screens.hpp"
#include "fullwindow.hpp"
#include "events.hpp"

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"

FullWindow* Init::Init() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    auto screen = Static::Screens::ScreenNames::NULL_SCREEN;
    auto fullWindow = new FullWindow(
        SDL_CreateWindow("Arrowpen", 200, 200, 1000, 500, SDL_WINDOW_RESIZABLE),
        screen,
        Static::Events::GenericEventHandler()
    );
    return fullWindow;
}