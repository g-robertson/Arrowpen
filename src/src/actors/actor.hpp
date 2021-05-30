#pragma once

#include <experimental/memory>
#include <memory>
#include "SDL2/SDL.h"

#include "helpers.hpp"

namespace Static {
    namespace Screens {
        class Screen;
    };
};


class Actor {
    public:
        virtual void Draw(SDL_Renderer* renderer) = 0;
        virtual bool Handle(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent) = 0;
        virtual void FocusHandle(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent) {};
        
        virtual const std::experimental::observer_ptr<SDL_Rect> rectg() = 0;
};