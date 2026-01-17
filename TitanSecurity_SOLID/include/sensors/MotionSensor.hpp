#pragma once 
#include "sensors/IMotion.hpp"
#include "main/Sensor.hpp"

class MotionSensor final : public Sensor, public IMotion {
        private:
                bool motion{false};        

        public:
                MotionSensor(std::string n, std::string l) : Sensor(std::move(n), std::move(l)) {}

                //getter, setter
                virtual bool isMotion() const override { return motion; }
                void setMotion(bool m) { motion = m; }
};
