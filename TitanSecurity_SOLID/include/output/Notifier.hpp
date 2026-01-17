#pragma once
#include "output/INotifier.hpp"

class Notifier : public INotifier {
    private:
        void notyfyUserPhone(const std::string& msg) {
                std::cout << "[PHONE] " << msg << std::endl;
        }

        void callPolice(const std::string& number) {
                std::cout << "[CALLING] " << number << std::endl;
        }

        void call(const std::string& number) {
                std::cout << "[CALLING] " << number << std::endl;
        }

    public:
        void notyfy(Type type) override { 
        switch (type) {
            case Type::DoorIntrusion: notyfyUserPhone("Door opened!"); break;
            case Type::MotionDetected: notyfyUserPhone("Motion detected!"); callPolice("1-02"); break;
            case Type::Fire: call("911"); break;
        }
    }
};
