#pragma once

#include <memory>

#include "sm.hpp"

class SMReader {
    public:
        SMReader() {
        }
        std::shared_ptr<SMSong> Read(const std::string path);
};