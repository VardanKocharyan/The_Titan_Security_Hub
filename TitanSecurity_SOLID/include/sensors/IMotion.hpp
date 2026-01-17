#pragma once

class IMotion {
    public:
        virtual ~IMotion() = default;
        virtual bool isMotion() const  = 0;
};

