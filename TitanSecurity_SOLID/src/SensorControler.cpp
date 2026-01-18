#include "main/SensorControler.hpp"

void SensorControler::poll(const std::vector<Sensor*>& sensors, const SystemMode& mode) {
    for (size_t i{}; i < sensors.size(); ++i) {
        //door
        if (OpenState* door = dynamic_cast<OpenState*>(sensors[i])) {
            if (door->isOpen() && mode.isArmed()) {
                alarm.trigger();
                logger.log("Door intrusion");
                notifier.notyfy(Type::DoorIntrusion);
            }
        }
        //sharj ka te che 
        if (IMotion* motion = dynamic_cast<IMotion*>(sensors[i])) {
            if (motion->isMotion() && mode.isArmed()) {
                notifier.notyfy(Type::MotionDetected);
                logger.log("Motion detected");
            }
        }
        //temperatur
        if (ITemperature* heat = dynamic_cast<ITemperature*>(sensors[i])) {
            if (heat->getTemperature() > 50) {
                alarm.trigger();
                notifier.notyfy(Type::Fire);
                logger.log("Fire detected");
            }
        }
    }
}
