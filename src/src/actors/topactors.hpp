#pragma once
#include "SDL2/SDL.h"
#include <memory>
#include <set>
#include <list>

#include <experimental/memory>
#include "floatactor.hpp"

class TopActors {
    public:
        TopActors();
        TopActors(std::initializer_list<FloatActor*> actors);
        TopActors(std::initializer_list<FloatActor*> actors, int rw, int rh);

        void Draw(SDL_Renderer* renderer);
        bool Handle(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent);
        void FocusHandle(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent);

        void ChangeParentDimensions(int rw, int rh);

        void RegisterEvent(Uint32 eventType);
        bool RegisteredEvent(Uint32 eventType);
        void UnregisterEvents();


        const std::experimental::observer_ptr<Actor> FocusedActor();
    private:
        std::set<Uint32> eventsRegistered;
        std::list<std::unique_ptr<FloatActor, FloatActor_Destroy>> actors;

        std::experimental::observer_ptr<Actor> focusedActor;
};