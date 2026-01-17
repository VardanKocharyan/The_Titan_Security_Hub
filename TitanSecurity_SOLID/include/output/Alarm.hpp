#pragma once 
#include "output/IAlarm.hpp"

class Alarm : public IAlarm {
    public:
        virtual void trigger() override {
            std::cout << "ALARM!!!" << std::endl;
        }      
};
