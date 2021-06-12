#pragma once
#include <memory>
#include <set>
#include <forward_list>
#include <list>
#include "floatactor.hpp"

class TopActors {
    public:
        TopActors(int usedIntX = 0, int usedIntY = 0, float usedFloatX = 0, float usedFloatY = 0);
        TopActors(std::initializer_list<std::pair<bool, Actor*>> actors, int usedIntX = 0, int usedIntY = 0, float usedFloatX = 0, float usedFloatY = 0);
        TopActors(int rw, int rh, std::initializer_list<std::pair<bool, Actor*>> actors, int usedIntX = 0, int usedIntY = 0, float usedFloatX = 0, float usedFloatY = 0);

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
        int usedIntX;
        int usedIntY;
        float usedFloatX;
        float usedFloatY;
        std::set<Uint32> eventsRegistered;
        std::forward_list<FloatActor*> floatActors;
        std::list<std::unique_ptr<Actor, Actor_Destroy>> actors;

        Actor* focusedActor;
};