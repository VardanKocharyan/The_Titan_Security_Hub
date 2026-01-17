#pragma once
#include "output/ILogger.hpp"

class Logger : public ILogger {
    public:
        virtual void log(const std::string& msg) override {
            std::cout << msg << std::endl;
        }
};
