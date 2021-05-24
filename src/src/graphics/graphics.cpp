#include "graphics.hpp"

Graphics::Graphics() {

}

void Graphics::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderClear(renderer);
    for (size_t i = 0; i < this->actors.size(); ++i) {
        this->actors[i]->Draw(renderer);
    }
}