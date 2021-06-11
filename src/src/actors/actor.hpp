#pragma once

#include <experimental/memory>
#include <memory>
#include <list>
#include "SDL2/SDL.h"

#include "helpers.hpp"
#include "sdlhelp.hpp"

namespace Static {
    namespace Screens {
        class Screen;
    };
};


class Actor {
    public:
        virtual void Draw(UPtrSDL_Renderer&) = 0;
        virtual bool Handle(Static::Screens::Screen*, SDL_Event&) = 0;
        virtual void FocusHandle(Static::Screens::Screen*, SDL_Event&) {};
        virtual std::list<UPtrSDL_Texture> Init(UPtrSDL_Renderer&) {return std::list<UPtrSDL_Texture>();}

        virtual const SDL_Rect* rectg() = 0;

        virtual ~Actor() {};
};

struct Actor_Destroy {
    void operator() (Actor* actor) {
        delete actor;
    }
};