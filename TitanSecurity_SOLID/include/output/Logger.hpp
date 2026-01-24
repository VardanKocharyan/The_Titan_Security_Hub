#pragma once
#include "output/ILogger.hpp"
#include <fstream>

class Logger : public ILogger {
    std::ofstream file;

public:
    explicit Logger(const std::string& filename);
    ~Logger();

    void log(const std::string& msg) override;
};

