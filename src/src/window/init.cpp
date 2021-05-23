
#include <memory>

#include "init.hpp"
#include "screens.hpp"
#include "fullwindow.hpp"
#include "events.hpp"
#include "graphics.hpp"
#include "SDL2/SDL.h"

FullWindow* Init::Init() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Window* window= SDL_CreateWindow("IDK Homie", 200, 200, 1000, 500, SDL_WINDOW_RESIZABLE);

    Static::Screens::ScreenNames screen = Static::Screens::ScreenNames::NULL_SCREEN;
    
    FullWindow* fullWindow = new FullWindow(
        window,
        screen,
        Static::Events::GenericEventHandler()
    );
    return fullWindow;
}