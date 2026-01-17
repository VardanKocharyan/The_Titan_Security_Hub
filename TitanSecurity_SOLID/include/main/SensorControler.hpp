#pragma once
#include <vector>
#include "main/SystemMode.hpp"
#include "main/Sensor.hpp"

#include "sensors/OpenState.hpp"
#include "sensors/IMotion.hpp"
#include "sensors/ITemperature.hpp"

#include "output/IAlarm.hpp"
#include "output/ILogger.hpp"
#include "output/INotifier.hpp"

class SensorControler {
            private:
        IAlarm& alarm;
        ILogger& logger;
        INotifier& notifier;

    public:
        SensorControler(IAlarm& a, ILogger& l, INotifier& n) : alarm{a}, logger{l}, notifier{n} {}

        void poll(const std::vector<Sensor*>& sensors, const SystemMode& mode);
};
