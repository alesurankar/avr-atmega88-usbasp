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
            Increment(0.6f);
        }
        else {
            Decrement(0.6f);
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
    void Increment(float val) {
        if (bright < 30.0f) {
            bright += val;
        }
        else if (bright >= 30.0f && bright < 100.0f) {
            bright += (2*val);
        }
        else if (bright >= 100.0f && bright < 165.0f){
            bright += (5*val);
        }
        else  {
            bright += (9*val);
        }
        if (bright >= 250.0f) {
            counter++;
            if (counter > 3) {
                counter = 3;
                Reverse();
            }
            else {
                bright = 0.0f;
            }
            change = true;
            _delay_ms(20);
            
        }
    }
    void Decrement(float val) {
        if (bright >= 185.0f) {
            bright -= (9*val);
        } 
        if (bright >= 100.0f && bright < 175.0f) {
            bright -= (5*val);
        } 
        else if (bright >= 20.0f && bright < 100.0f) {
            bright -= (2*val);
        }
        else {
            bright -= val;
        }
        if (bright <= 0.5f) {
            counter--;
            if (counter < 0) {
                counter = 0;
                Reverse();
                _delay_ms(20);
            }
            else {
                bright = 255.0f;
                _delay_ms(20);
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
    float bright = 0.0f;
    bool increment = true;
    bool change = true;
};