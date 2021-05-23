#include <iostream>
#include <fstream>
#include <filesystem>

#include "helpers.hpp"
#include "logging.hpp"


void Logging::Log(std::string message, std::string logLocation, std::string additionalDirectory, bool timestamp, bool flushOfs) {
    std::filesystem::create_directory("logs");
    if (additionalDirectory == "") {
        additionalDirectory = "logs";
    } else {
        additionalDirectory = "logs/" + additionalDirectory;
    }
    std::filesystem::create_directory(additionalDirectory);

    logLocation = additionalDirectory + "/" + logLocation;
    if (timestamp) {
        logLocation += "-" + Util::Date::getISOISHString();
    }
    logLocation += ".log";
    
    std::ofstream ofs = std::ofstream(logLocation);
    ofs << message;
    if (flushOfs) {
        ofs.flush();
    }
}

void Logging::Error(std::string message) {
    Logging::Log(message, "Crash", "Crashes", true);
    throw new LOGGED_CRASH_EXCEPTION;
}