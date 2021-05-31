#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <experimental/memory>
#include "SDL2/SDL.h"

namespace Util {
    namespace Char {
        bool isWhitespace(char c);
    }

    namespace Date {
        constexpr char DEFAULT_ISOISH_STRING[] = "0000-00-00T00-00-00";
        constexpr size_t ISOISH_TIME_SIZE = sizeof(DEFAULT_ISOISH_STRING);
        std::string getISOISHString(time_t t = time(0));
    }

    namespace File {
        std::streamoff passComments(std::ifstream& is, char c);
        std::string readSubstr(std::ifstream& is, const std::streamoff& start, const std::streamoff& len);
    }
}

// events.hpp & eventCallback.hpp help
namespace Static {
    namespace Screens {
        class Screen;
    };
};

typedef bool (*event_callback_t)(std::experimental::observer_ptr<Static::Screens::Screen>, SDL_Event&);
typedef std::map<Uint32, event_callback_t> event_callback_map_t;
inline bool noEventCallback(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent) {
    return true;
}

// actor.hpp help
#define NoDraw() void Draw(UPtrSDL_Renderer& renderer) {}
#define NoHandle() bool Handle(std::experimental::observer_ptr<Static::Screens::Screen> screen, SDL_Event& sdlEvent) {return true;}
bool InBounds(int x, int y, const SDL_Rect& rect);