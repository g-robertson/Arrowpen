#pragma once
#include "SDL2/SDL.h"
#include <memory>
#include <forward_list>

#include "floatactor.hpp"

class TopActors {
    public:
        TopActors();
        TopActors(std::initializer_list<FloatActor*> actors);
        TopActors(std::initializer_list<FloatActor*> actors, int rw, int rh);
        void Draw(SDL_Renderer* renderer);
        bool Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent);

        void ChangeParentDimensions(int rw, int rh);
    private:

        std::forward_list<std::shared_ptr<FloatActor>> actors;
};