#include "actors.hpp"

ActorsActor::ActorsActor() {

}

ActorsActor::ActorsActor(std::initializer_list<Actor*> actors) {
    this->actors.reserve(actors.size());
    for (size_t i = 0; i < actors.size(); ++i) {
        this->actors.push_back(std::shared_ptr<Actor>(actors.begin()[i]));
    }
}

void ActorsActor::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderClear(renderer);
    for (size_t i = 0; i < this->actors.size(); ++i) {
        this->actors[i]->Draw(renderer);
    }
    SDL_RenderPresent(renderer);
}

bool ActorsActor::Handle(FullWindow* fullWindow, std::weak_ptr<SDL_Event> sdlEvent) {
    for (size_t i = 0; i < this->actors.size(); ++i) {
        if (!this->actors[i]->Handle(fullWindow, sdlEvent)) {
            return false;
        }
    }
    return true;
}