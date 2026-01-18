#pragma once
#include "sensors/ITemperature.hpp"
#include "main/Sensor.hpp"

class HeatSensor final : public Sensor, public ITemperature {
    private:
        int temperatur{24};

    public:
        HeatSensor(std::string n, std::string l) : Sensor(std::move(n), std::move(l)) {}

        //getter
        virtual int getTemperature() const override{ return temperatur; }
        //setter
        void setTemperature(int t) { temperatur = t; }
};
