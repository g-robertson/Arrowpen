#pragma once
#include <list>

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
        virtual bool Handle(Static::Screens::Screen*, SDL_Event&) {return true;};
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