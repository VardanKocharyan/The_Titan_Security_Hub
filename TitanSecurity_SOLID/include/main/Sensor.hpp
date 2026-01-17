#pragma once 
#include <string>

class Sensor {
    protected:
        std::string name;
        std::string location;

    public:
        Sensor(const std::string n = "Unnamed", const std::string l = "NoLocation") : name{std::move(n)}, location{std::move(l)} {}
        virtual ~Sensor() = default;
        
        //getters
        const std::string getName() const noexcept { return name; }
        const std::string getLocation() const noexcept { return location; }
};
