#include <memory>

#include "helpers.hpp"

#include "init.hpp"
#include "events.hpp"
#include "screens.hpp"
#include "fullwindow.hpp"
#include "events.hpp"

#include "sdlhelp.hpp"
#include "SDL2/SDL.h"

constexpr static int W_STANDARD = 1366;
constexpr static int H_STANDARD = 768;
constexpr static int H_MIN = 400;

constexpr static int W_MIN = cexprceil(static_cast<float>(H_MIN) * (static_cast<float>(W_STANDARD) / static_cast<float>(H_STANDARD)));

std::unique_ptr<FullWindow> Init::Init(SDL_Context* context) {
    auto screen = Static::Screens::ScreenNames::TEST_SCREEN;
    auto fullWindow = std::make_unique<FullWindow>(FullWindow(
        context,
        screen,
        Static::Events::GenericEventHandler.get()
    ));
    SDL_SetWindowMinimumSize(fullWindow->context->window.get(), W_MIN, H_MIN);
    SDL_Event initEvent;
    initEvent.type = Static::Events::INIT_EVENT;
    SDL_PushEvent(&initEvent);
    return fullWindow;
}