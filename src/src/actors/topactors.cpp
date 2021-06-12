#include "topactors.hpp"
TopActors::TopActors(int usedIntX, int usedIntY, float usedFloatX, float usedFloatY) {
    this->usedIntX = usedIntX;
    this->usedIntY = usedIntY;
    this->usedFloatX = usedFloatX;
    this->usedFloatY = usedFloatY;
}

TopActors::TopActors(std::initializer_list<std::pair<bool, Actor*>> actors, int usedIntX, int usedIntY, float usedFloatX, float usedFloatY) :
TopActors::TopActors(usedIntX, usedIntY, usedFloatX, usedFloatY) {
    for (auto actor = actors.begin(); actor != actors.end(); ++actor) {
        this->actors.emplace_back(std::unique_ptr<Actor, Actor_Destroy>(actor->second));
        // is FloatActor
        if (actor->first) {
            this->floatActors.emplace_front(dynamic_cast<FloatActor*>(actor->second));
        }
    }
}

TopActors::TopActors(int rw, int rh, std::initializer_list<std::pair<bool, Actor*>> actors, int usedIntX, int usedIntY, float usedFloatX, float usedFloatY) :
TopActors::TopActors(usedIntX, usedIntY, usedFloatX, usedFloatY) {
    for (auto actor = actors.begin(); actor != actors.end(); ++actor) {
        this->actors.emplace_back(std::unique_ptr<Actor, Actor_Destroy>(actor->second));
        // is FloatActor
        if (actor->first) {
            this->floatActors.emplace_front(dynamic_cast<FloatActor*>(actor->second));
            dynamic_cast<FloatActor*>(actor->second)->ChangeParentDimensions(rw, rh);
        }
    }
}

std::list<UPtrSDL_Texture> TopActors::InitActors(UPtrSDL_Renderer& renderer) {
    std::list<UPtrSDL_Texture> inittedTextures;
    for (auto actor = this->actors.begin(); actor != this->actors.end(); ++actor) {
        auto actorInittedTextures = (*actor)->Init(renderer);
        inittedTextures.splice(inittedTextures.end(), actorInittedTextures);
    }
    return inittedTextures;
}

void TopActors::ChangeParentDimensions(int rw, int rh) {
    for (auto floatActor = this->floatActors.begin(); floatActor != this->floatActors.end(); ++floatActor) {
        (*floatActor)->ChangeParentDimensions(rw, rh);
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

void TopActors::Draw(UPtrSDL_Renderer& renderer) {
    // Draw forwards
    for (auto actor = this->actors.begin(); actor != this->actors.end(); ++actor) {
        (*actor)->Draw(renderer);
    }
}

bool TopActors::Handle(Static::Screens::Screen* screen, SDL_Event& sdlEvent) {
    // Handle backwards, so that event registering happens first on the top-most actors
    for (auto actor = this->actors.rbegin(); actor != this->actors.rend(); ++actor) {
        if (!(*actor)->Handle(screen, sdlEvent)) {
            return false;
        }
    }
    return true;
}

void TopActors::FocusHandle(Static::Screens::Screen* screen, SDL_Event& sdlEvent) {
    switch (sdlEvent.type) {
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEWHEEL:
            for (auto actor = this->actors.rbegin(); actor != this->actors.rend(); ++actor) {
                if (InBounds(sdlEvent.button.x, sdlEvent.button.y, *(*actor)->rectg())) {
                    (*actor)->FocusHandle(screen, sdlEvent);
                    this->focusedActor = (*actor).get();
                    return;
                }
        }
    }
}

const Actor* TopActors::FocusedActor() {
    return this->focusedActor;
}