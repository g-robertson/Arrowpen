#pragma once

#include <string>
#include <map>
#include <memory>
#include "SDL2/SDL.h"

#define SharedNewPtr(type, ...) std::shared_ptr<type>(new type(__VA_ARGS__))

namespace Util {
    namespace Char {
        bool isWhitespace(char c);
    }

    namespace Date {
        const char DEFAULT_ISOISH_STRING[] = "0000-00-00T00-00-00";
        const size_t ISOISH_TIME_SIZE = sizeof(DEFAULT_ISOISH_STRING);
        std::string getISOISHString(time_t t = time(0));
    }

    namespace File {
        std::streamoff passComments(std::ifstream& is, char c);
        std::string readSubstr(std::ifstream& is, const std::streamoff& start, const std::streamoff& len);
    }
}

// events.hpp & eventCallback.hpp help
class FullWindow;

typedef bool (*event_callback_t)(FullWindow*, std::shared_ptr<SDL_Event>);
typedef std::map<Uint32, event_callback_t> event_callback_map_t;
inline bool noEventCallback(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {
    return true;
}

// actor.hpp help
#define NoDraw() void Draw(SDL_Renderer* renderer) {}
#define NoHandle() bool Handle(FullWindow* fullWindow, std::shared_ptr<SDL_Event> sdlEvent) {return true;}
bool InBounds(int x, int y, const SDL_Rect& rect);