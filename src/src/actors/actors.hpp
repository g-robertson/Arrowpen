#pragma once
#include "SDL2/SDL.h"
#include <memory>
#include <forward_list>

#include "actor.hpp"

class ImmutableActorsActor : public Actor {
    public:
        ImmutableActorsActor();
        ImmutableActorsActor(std::initializer_list<Actor*> actors);
        void Draw(SDL_Renderer* renderer);
        bool Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent);
    private:
        std::forward_list<std::shared_ptr<Actor>> actors;
};