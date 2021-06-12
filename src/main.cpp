#include <memory>
#include <filesystem>
#include "sm.hpp"
#include "smwriter.hpp"
#include "smreader.hpp"

#include "init.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

const std::string test = "/home/gr/Desktop/Arrowpen/Songs/Gochamaze Greatest Gigapack 2/(STEPDWI)INSIDE IDENTITY/edit.sm";
int main(int, char**) {
    /*
    auto reader = std::shared_ptr<SMReader>(new SMReader());
    auto song = reader->Read(test);
    auto writer = std::shared_ptr<SMWriter>(new SMWriter());
    writer->Write(song, "asdf.sm");
    */
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    {
        // context & actor initing defined externally to prevent renderer from being destructed before actors
        auto window = UPtrSDL_Window(SDL_CreateWindow("Arrowpen", 200, 200, 1000, 500, SDL_WINDOW_RESIZABLE));
        auto context = std::make_unique<SDL_Context>(SDL_Context(std::move(window)));
        auto screenTextures = Static::Screens::Init(context->renderer);
        auto fullWindow = Init::Init(context.get());
        fullWindow->Listen(true);
    }
    SDL_Quit();
    exit(0);
}