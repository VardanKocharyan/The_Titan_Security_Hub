#pragma once 

class OpenState {
    public:
        virtual ~OpenState() = default;
        virtual bool isOpen() const = 0;
};
