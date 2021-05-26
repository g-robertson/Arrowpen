#include "actors.hpp"

ImmutableActorsActor::ImmutableActorsActor() {

}

ImmutableActorsActor::ImmutableActorsActor(std::initializer_list<Actor*> actors) {
    for (size_t i = 0; i < actors.size(); ++i) {
        this->actors.emplace_front(std::shared_ptr<Actor>(actors.begin()[i]));
    }
}

void ImmutableActorsActor::Draw(SDL_Renderer* renderer) {
    for (auto actor = this->actors.begin(); actor != this->actors.end(); ++actor) {
        (*actor)->Draw(renderer);
    }
}

bool ImmutableActorsActor::Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {
    for (auto actor = this->actors.begin(); actor != this->actors.end(); ++actor) {
        if (!(*actor)->Handle(fullWindow, sdlEvent)) {
            return false;
        }
    }
    return true;
}