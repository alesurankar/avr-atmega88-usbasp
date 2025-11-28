#include "Pin.hpp"
#include <util/delay.h>

class Blinking 
{
public:
    enum class TYPE {
        BL1,
        BL2
    };
    Blinking() {
        led.setOutput();
    }
    void Blink1() {
        blinkCounter = 0;
        type = TYPE::BL1;
    }
    void Blink2() {
        blinkCounter = 0;
        type = TYPE::BL2;
    }
    void Update() {
        switch(type) {
            case (TYPE::BL1):
                if(blinkCounter <= 200) {
                    if(blinkCounter <= 100) {
                        led.high();
                    }
                    else {
                        led.low();
                    }
                }
                else {
                    blinkCounter = 0;
                }
                blinkCounter++;
                _delay_ms(1);
                break;
            case (TYPE::BL2):
                if(blinkCounter <= 2000) {
                    if(blinkCounter <= 1000) {
                        led.high();
                    }
                    else if (blinkCounter <= 1333) {
                        led.low();
                    }
                    else if (blinkCounter <= 1666) {
                        led.high();
                    }
                    else {
                        led.low();
                    }
                }
                else {
                    blinkCounter = 0;
                }
                blinkCounter++;
                _delay_ms(1);
                break;
        }
    }
private:
    pin::pb3 led;
    TYPE type = TYPE::BL1;
    int blinkCounter = 0;
    bool ledOn = false;;
};