#pragma once

class ITemperature {
    public:
        virtual ~ITemperature() = default;
        virtual int getTemperature() const = 0;
};
