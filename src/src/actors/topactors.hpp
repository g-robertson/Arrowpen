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
        std::list<std::unique_ptr<FloatActor, FloatActor_Destroy>> actors;

        Actor* focusedActor;
};