#include "../lib/Pin.hpp"

class Blinking 
{
public:
    enum class TYPE {
        BL1,
        BL2
    };
    Blinking();
    void Blink(TYPE type_in);
    void Update();
private:
    void Prog1();
    void Prog2();
private:
    pin::pd7 led;
    TYPE type;
    int blinkCounter;
    bool ledOn;
};