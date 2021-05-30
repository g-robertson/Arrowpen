#include "helpers.hpp"
#include "topactors.hpp"

TopActors::TopActors() {
}

TopActors::TopActors(std::initializer_list<FloatActor*> actors) {
    for (auto actor = actors.begin(); actor != actors.end(); ++actor) {
        this->actors.emplace_back(std::shared_ptr<FloatActor>(*actor));
    }
}

TopActors::TopActors(std::initializer_list<FloatActor*> actors, int rw, int rh) {
    for (auto actor = actors.begin(); actor != actors.end(); ++actor) {
        this->actors.emplace_back(std::shared_ptr<FloatActor>(*actor));
        (*actor)->ChangeParentDimensions(rw, rh);
    }
}

void TopActors::ChangeParentDimensions(int rw, int rh) {
    for (auto actor = this->actors.begin(); actor != this->actors.end(); ++actor) {
        (*actor)->ChangeParentDimensions(rw, rh);
    }
}

void TopActors::RegisterEvent(Uint32 eventType) {
    this->eventsRegistered.insert(eventType);
}

bool TopActors::RegisteredEvent(Uint32 eventType) {
    return this->eventsRegistered.find(eventType) != this->eventsRegistered.end();
}

void TopActors::UnregisterEvents() {
    this->eventsRegistered.clear();
}

void TopActors::Draw(SDL_Renderer* renderer) {
    // Draw forwards
    for (auto actor = this->actors.begin(); actor != this->actors.end(); ++actor) {
        (*actor)->Draw(renderer);
    }
}

bool TopActors::Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {
    // Handle backwards, so that event registering happens first on the top-most actors
    for (auto actor = this->actors.rbegin(); actor != this->actors.rend(); ++actor) {
        if (!(*actor)->Handle(fullWindow, sdlEvent)) {
            return false;
        }
    }
    return true;
}