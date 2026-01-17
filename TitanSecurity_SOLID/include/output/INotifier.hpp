#pragma once 
#include <string>

enum class Type {
    DoorIntrusion,
    MotionDetected,
    Fire
};

class INotifier {
    public:
        virtual ~INotifier() = default;
        virtual void notyfy(Type type) = 0;
};
