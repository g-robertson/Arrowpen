#pragma once
#include "SDL2/SDL.h"
#include <memory>
#include <vector>

#include "actor.hpp"

class ActorsActor : public Actor {
    public:
        ActorsActor();
        ActorsActor(std::initializer_list<Actor*> actors);
        void Draw(SDL_Renderer* renderer);
        bool Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent);
        std::vector<std::shared_ptr<Actor>> actors;
};