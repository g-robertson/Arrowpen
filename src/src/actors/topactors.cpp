#include "helpers.hpp"
#include "topactors.hpp"

TopActors::TopActors() {
}

TopActors::TopActors(std::initializer_list<FloatActor*> actors, int rw, int rh) : TopActors() {
    for (auto actor = std::rbegin(actors); actor != std::rend(actors); ++actor) {
        this->actors.emplace_front(std::shared_ptr<FloatActor>(*actor));
        (*actor)->ChangeParentDimensions(rw, rh);
    }
}

TopActors::TopActors(std::initializer_list<FloatActor*> actors) : TopActors() {
    for (auto actor = std::rbegin(actors); actor != std::rend(actors); ++actor) {
        this->actors.emplace_front(std::shared_ptr<FloatActor>(*actor));
    }
}

void TopActors::ChangeParentDimensions(int rw, int rh) {
    for (auto actor = this->actors.begin(); actor != this->actors.end(); ++actor) {
        (*actor)->ChangeParentDimensions(rw, rh);
    }
}

void TopActors::Draw(SDL_Renderer* renderer) {
    for (auto actor = this->actors.begin(); actor != this->actors.end(); ++actor) {
        (*actor)->Draw(renderer);
    }
}

bool TopActors::Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {
    for (auto actor = this->actors.begin(); actor != this->actors.end(); ++actor) {
        if (!(*actor)->Handle(fullWindow, sdlEvent)) {
            return false;
        }
    }
    return true;
}