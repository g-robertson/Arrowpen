#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "SDL2/SDL.h"

template <typename T>
constexpr int cexprfloor(T number) {
    return (number == static_cast<T>(static_cast<int>(number))) ? number :static_cast<int>(number + ((number > 0) ? 0 : -1));
}

template <typename T>
constexpr int cexprceil(T number) {
    return (number == static_cast<T>(static_cast<int>(number))) ? number : static_cast<int>(number + ((number > 0) ? 1 : 0));
}

namespace Util {
    namespace Char {
        bool isWhitespace(char c);
    }

    namespace Date {
        constexpr static char DEFAULT_ISOISH_STRING[] = "0000-00-00T00-00-00";
        constexpr static size_t ISOISH_TIME_SIZE = sizeof(DEFAULT_ISOISH_STRING);
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

typedef bool (*event_callback_t)(Static::Screens::Screen*, SDL_Event&);
typedef std::map<Uint32, event_callback_t> event_callback_map_t;
inline bool noEventCallback(Static::Screens::Screen*, SDL_Event&) {
    return true;
}

// actor.hpp help
#define NoDraw() void Draw(UPtrSDL_Renderer&) {}
bool InBounds(int x, int y, const SDL_Rect& rect);