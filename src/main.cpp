#include <memory>
#include <iostream>

#include "sm.hpp"
#include "smwriter.hpp"
#include "smreader.hpp"

#include "init.hpp"

#include "SDL2/SDL.h"

const std::string test = "/home/gr/Desktop/Arrowpen/Songs/Gochamaze Greatest Gigapack 2/(STEPDWI)INSIDE IDENTITY/edit.sm";
int main(int argc, char** argv) {
    auto reader = std::shared_ptr<SMReader>(new SMReader());
    auto song = reader->Read(test);
    auto writer = std::shared_ptr<SMWriter>(new SMWriter());
    writer->Write(song, "asdf.sm");
    {
        // guess: probably something to do with sdl_window trying to destroy itself, but fullWindow not existing anymore
        // having fullWindow as shared ptr causes segfault for some ungodly reason I cannot figure out
        // todo: make it a shared ptr, but for now I cannot be bothered so it will be a raw pointer
        FullWindow* fullWindow = Init::Init();
        fullWindow->Listen(true);
        delete fullWindow;
    }
    SDL_Quit();
    return 0;
}