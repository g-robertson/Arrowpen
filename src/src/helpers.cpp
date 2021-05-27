#include <iostream>
#include <ctime>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>
#include "helpers.hpp"

bool Util::Char::isWhitespace(char c) {
    return c == ' ' || c == '\f' || c == '\r' || c == '\n' || c == '\t' || c == '\v';
}

std::string Util::Date::getISOISHString(time_t t) {
    char buffer[Util::Date::ISOISH_TIME_SIZE];
    strncpy(buffer, Util::Date::DEFAULT_ISOISH_STRING, Util::Date::ISOISH_TIME_SIZE);
    strftime(buffer, sizeof(buffer), "%FT%H-%M-%S", gmtime(&t));
    std::string result(buffer, Util::Date::ISOISH_TIME_SIZE);
    return result;
}

std::streamoff Util::File::passComments(std::ifstream& is, char c) {
    if (c == '/' && is.peek() == '/') {
        std::streamoff prev = is.tellg();
        while (is.get(c)) {
            if (is.peek() == '\n') {
                break;
            }
        }
        return prev;
    } else {
        return std::char_traits<char>::eof();
    }
}

std::string Util::File::readSubstr(std::ifstream& is, const std::streamoff& start, const std::streamoff& len) {
    std::streamoff prev = is.tellg();
    char* out = new char[len];
    
    is.seekg(start);
    is.readsome(out, len);
    std::string result(out, len);
    delete[] out;

    is.seekg(prev);

    return result;
}

bool InBounds(int x, int y, const SDL_Rect& rect) {
    return x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h;
}