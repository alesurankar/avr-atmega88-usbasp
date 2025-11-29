#include "Pin.hpp"

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
    pin::pb3 led;
    TYPE type;
    int blinkCounter;
    bool ledOn;;
};