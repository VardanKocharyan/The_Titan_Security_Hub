#pragma once 
#include <iostream>

class IAlarm {
    public:
        virtual ~IAlarm() = default;
        virtual void trigger() = 0;
};


