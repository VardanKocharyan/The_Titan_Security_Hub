#include <iostream>
#include <vector>
#include <exception>

// core
#include "main/SystemMode.hpp"
#include "main/SensorControler.hpp"

// sensors
#include "sensors/DoorSensor.hpp"
#include "sensors/MotionSensor.hpp"
#include "sensors/HeatSensor.hpp"

// output
#include "output/Alarm.hpp"
#include "output/Logger.hpp"
#include "output/Notifier.hpp"

int main(void) {
  try {
      std::cout << "--- Titan Security System v2.0 ---\n";

        /* 1️⃣ Create sensors */
        DoorSensor frontDoor("Front Door", "Entry");
        MotionSensor motion("Living Room Motion", "Living Room");
        HeatSensor heat("Kitchen Heat", "Kitchen");

        /* 2️⃣ Create outputs */
        Alarm alarm;
        Logger logger;
        Notifier notifier;

        /* 3️⃣ System mode */
        SystemMode mode;
        mode.setMode(SystemMode::Mode::Away);

        /* 4️⃣ Controller */
        SensorControler controller(alarm, logger, notifier);

        /* 5️⃣ Sensor collections */
        std::vector<Sensor*> sensors = {
            &frontDoor,
            &motion,
            &heat
        };

        /* -------- Normal check -------- */
        std::cout << "\n[SIMULATION] Normal state\n";
        controller.poll(sensors, mode);

        /* -------- Intruder scenario -------- */
        std::cout << "\n[SIMULATION] Intruder opens front door\n";
        frontDoor.setOpen(true);

        controller.poll(sensors, mode);

        /* -------- Fire scenario -------- */
        std::cout << "\n[SIMULATION] Kitchen catches fire\n";
        heat.setTemperature(75);

        controller.poll(sensors, mode);

    } catch (const std::exception& e) {
        std::cout << "CRITICAL ERROR: " << e.what() << std::endl;
  }

    return 0;
}
