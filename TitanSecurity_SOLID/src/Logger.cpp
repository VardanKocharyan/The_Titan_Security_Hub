#include "output/Logger.hpp"
#include <ctime>

Logger::Logger(const std::string& filename) {
    file.open(filename, std::ios::app);
}

Logger::~Logger() {
    if (file.is_open())
        file.close();
}

void Logger::log(const std::string& msg) {
    if (!file.is_open()) return;

    std::time_t now = std::time(nullptr);
    char buf[26];
    std::strftime(buf, sizeof(buf),
                  "%Y-%m-%d %H:%M:%S",
                  std::localtime(&now));

    file << "[" << buf << "] "
         << msg << '\n';
}
