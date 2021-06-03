#include "topactors.hpp"
#include "sdlhelp.hpp"
TopActors::TopActors() {
}

TopActors::TopActors(std::initializer_list<FloatActor*> actors) {
    for (auto actor = actors.begin(); actor != actors.end(); ++actor) {
        this->actors.emplace_back(std::unique_ptr<FloatActor, FloatActor_Destroy>(*actor));
    }
}

TopActors::TopActors(std::initializer_list<FloatActor*> actors, int rw, int rh) {
    for (auto actor = actors.begin(); actor != actors.end(); ++actor) {
        (*actor)->ChangeParentDimensions(rw, rh);
        this->actors.emplace_back(std::unique_ptr<FloatActor, FloatActor_Destroy>(*actor));
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