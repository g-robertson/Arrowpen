#include <memory>

#include "helpers.hpp"

#include "init.hpp"
#include "events.hpp"
#include "screens.hpp"
#include "fullwindow.hpp"
#include "events.hpp"

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"

constexpr int W_STANDARD = 1366;
constexpr int H_STANDARD = 768;
constexpr int H_MIN = 400;
constexpr int W_MIN = static_cast<int>(std::ceil(static_cast<float>(H_MIN) * (static_cast<float>(W_STANDARD) / static_cast<float>(H_STANDARD))));

std::unique_ptr<FullWindow> Init::Init() {
    auto screen = Static::Screens::ScreenNames::TEST_SCREEN;
    auto fullWindow = std::make_unique<FullWindow>(FullWindow(
        UPtrSDL_Window(SDL_CreateWindow("Arrowpen", 200, 200, 1000, 500, SDL_WINDOW_RESIZABLE)),
        screen,
        Static::Events::GenericEventHandler
    ));
    SDL_SetWindowMinimumSize(fullWindow->window.get(), W_MIN, H_MIN);
    SDL_Event initEvent;
    initEvent.type = Static::Events::INIT_EVENT;
    SDL_PushEvent(&initEvent);
    return fullWindow;
}