#pragma once
#include <string>

namespace Logging {
    class LOGGED_CRASH_EXCEPTION {
    };
    void Log(std::string message, std::string logLocation = "Log", std::string additionalDirectory = "", bool timestamp = false, bool flushOfs = true);
    void Error(std::string message);
}