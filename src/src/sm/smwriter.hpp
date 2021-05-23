#pragma once

#include <memory>

#include "sm.hpp"

class SMWriter {
    public:
        SMWriter() {
        }
        bool Write(const std::shared_ptr<SMSong> song, const std::string path);
}; 
