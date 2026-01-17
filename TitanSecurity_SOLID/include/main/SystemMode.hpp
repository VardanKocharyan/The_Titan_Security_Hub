#pragma once

class SystemMode {
    public:
        enum class Mode { Day, Away, Night };
    private:
        Mode mode{Mode::Day};

    public:
        Mode getMode() const { return mode; }
        void setMode(Mode m) { mode  = m; }
        bool isArmed() const { 
                return (mode == Mode::Away || mode == Mode::Night); 
        }
};
