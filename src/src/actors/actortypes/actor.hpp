#pragma once
#include <list>
#include "sdlhelp.hpp"
#include "helpers.hpp"

namespace Static {
    namespace Screens {
        class Screen;
    };
};


class Actor {
    public:
        virtual ~Actor() {}
        virtual void Draw(UPtrSDL_Renderer&) = 0;
        virtual bool Handle(Static::Screens::Screen*, SDL_Event&) {return true;}
        virtual void FocusHandle(Static::Screens::Screen*, SDL_Event&) {}
        virtual std::list<UPtrSDL_Texture> Init(UPtrSDL_Renderer&) {return std::list<UPtrSDL_Texture>();}

        virtual const SDL_Rect* rectg() = 0;
};

struct Actor_Destroy {
    void operator() (Actor* actor) {
        delete actor;
    }
};