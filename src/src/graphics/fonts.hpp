#pragma once

#include <memory>
#include "sdlhelp.hpp"
#include "SDL2/SDL_ttf.h"

#include "Fonts/PT-Sans_Regular.hpp"

namespace {
    /*
    TTF_Font* TTF_InitAndOpenFont(const char* file, int ptsize) {
        if (!TTF_WasInit()) {
            TTF_Init();
        }
        return TTF_OpenFont(file, ptsize);
    }
    */
    TTF_Font* TTF_InitAndOpenFontRW(const unsigned char* font, int size, int ptsize) {
        if (!TTF_WasInit()) {
            TTF_Init();
        }
        return TTF_OpenFontRW(SDL_RWFromConstMem(font, size), 1, ptsize);
    }
}

namespace Fonts {
    const auto Sans = UPtrTTF_Font(TTF_InitAndOpenFontRW(PTSansBytes, sizeof(PTSansBytes), 144));
}