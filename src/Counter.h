#include "../lib/Pin.hpp"
#include "../lib/PWM.hpp"
#include <util/delay.h>

class Counter
{
public:
    Counter() 
        :
        counter(0),
        bright(0),
        increment(true),
        change(true)
    {
        fltBit.InitTimer();
        bit1.SetOutput();
        bit2.SetOutput();
    }
    void Count() {
        if (increment) {
            Increment(1);
        }
        else {
            Decrement(1);
        }
        SetOutput();
        _delay_ms(1);
    }
    void Test() {
        fltBit.SetDutyCycle(155);
        bit1.High();
        bit2.Low();
    }
    void SetOutput() {
        fltBit.SetDutyCycle(bright);
        if (change) {
            change = false;
            switch (counter) {
            case 0:
                bit1.Low();
                bit2.Low();
                break;
            case 1:
                bit1.High();
                bit2.Low();
                break;
            case 2:
                bit1.Low();
                bit2.High();
                break;
            case 3:
                bit1.High();
                bit2.High();
                break;     
            }
        }
    }
private:
    void Increment(int val) {
        if (bright > 100) {
            bright += (2*val);
        }
        else {
            bright += val;
        }
        if (bright >= 254) {
            counter++;
            if (counter > 3) {
                Reverse();
                counter = 3;
            }
            else {
                bright = 0;
            }
            change = true;
            _delay_ms(500);
            
        }
    }
    void Decrement(int val) {
        if (bright > 100) {
            bright -= (2*val);
        } 
        else {
            bright -= val;
        }
        if (bright < 2) {
            counter--;
            _delay_ms(500);
            if (counter < 0) {
                Reverse();
                counter=0;
            }
            else {
                bright = 255;
            }
            change = true;
        }
    }
    void Reverse() {
        increment = !increment;
    }
private:
    pwm::pd5 fltBit;
    pin::pd6 bit1;
    pin::pd7 bit2;
    int counter = 0;
    int bright = 0;
    bool increment = true;
    bool change = true;
};