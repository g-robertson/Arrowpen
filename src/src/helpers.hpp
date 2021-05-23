#pragma once

#include <string>

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