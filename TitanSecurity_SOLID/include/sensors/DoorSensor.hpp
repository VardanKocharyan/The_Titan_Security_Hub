#pragma once 
#include "sensors/OpenState.hpp"
#include "main/Sensor.hpp"

class DoorSensor final : public Sensor, public OpenState {
    private:
        bool openState{false};

    public:
        DoorSensor(std::string n, std::string l) : Sensor(std::move(n), std::move(l)) {}

        //getter, setter
        virtual bool isOpen() const override { return openState; }
        void setOpen(bool state) { openState = state; } 
};

