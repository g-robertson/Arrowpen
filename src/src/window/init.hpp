#pragma once
#include <memory>

#include "fullwindow.hpp"

#include "SDL2/SDL.h"

namespace Init {
    std::unique_ptr<FullWindow> Init(SDL_Context* context);
}