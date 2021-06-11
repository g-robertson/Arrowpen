#pragma once
#include "SDL2/SDL.h"
#include <memory>
#include <set>
#include <forward_list>
#include <list>
#include <experimental/memory>
#include "floatactor.hpp"

class TopActors {
    public:
        TopActors();
        TopActors(std::initializer_list<std::pair<bool, Actor*>> actors);
        TopActors(std::initializer_list<std::pair<bool, Actor*>> actors, int rw, int rh);

        void Draw(UPtrSDL_Renderer& renderer);
        bool Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent);
        void FocusHandle(Static::Screens::Screen* screen, SDL_Event& sdlEvent);

        std::list<UPtrSDL_Texture> InitActors(UPtrSDL_Renderer& renderer);
        void ChangeParentDimensions(int rw, int rh);

        void RegisterEvent(Uint32 eventType);
        bool RegisteredEvent(Uint32 eventType);
        void UnregisterEvents();


        const Actor* FocusedActor();
    private:
        std::set<Uint32> eventsRegistered;
        std::forward_list<FloatActor*> floatActors;
        std::list<std::unique_ptr<Actor, Actor_Destroy>> actors;

        Actor* focusedActor;
};