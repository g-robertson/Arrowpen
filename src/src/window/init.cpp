
#include <memory>

#include "init.hpp"
#include "screens.hpp"
#include "fullwindow.hpp"
#include "events.hpp"
#include "graphics.hpp"

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"

FullWindow* Init::Init() {
    std::unique_ptr<SDL_Window, _SDL_DestroyWindow> window;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    window = std::unique_ptr<SDL_Window, _SDL_DestroyWindow>(SDL_CreateWindow("IDK Homie", 200, 200, 1000, 500, SDL_WINDOW_RESIZABLE));

    auto screen = Static::Screens::ScreenNames::NULL_SCREEN;
    
    auto fullWindow = new FullWindow(
        std::move(window),
        screen,
        Static::Events::GenericEventHandler()
    );
    return fullWindow;
}