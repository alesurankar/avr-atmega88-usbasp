#include <util/delay.h>
#include "Dimming.hpp"


Dimming::Dimming()
{
    led.InitTimer();
}

void Dimming::SetType(TYPE type_in)
{
    type = type_in;
}

void Dimming::SetTime(int time_in)
{
    time = time_in;
}

void Dimming::Update()
{   
    switch(type) {
        case (TYPE::DECR):
            Prog1();
            break;
        case (TYPE::INCR):
            Prog2();
            break;
    }
    led.SetDutyCycle((int)pwmCounter);
    _delay_ms(time);
}

void Dimming::Prog1()
{
    if (pwmCounter < 1.0f) {
        pwmCounter = 255.0f;
    }
    if (pwmCounter > 100.0f) {
        pwmCounter -= 2.0f;
    }
    else if (pwmCounter >= 20.0f && pwmCounter < 100.0f) {
        pwmCounter -= 1.0f;
    }
    else {
        pwmCounter -= 0.4f;
    }
}

void Dimming::Prog2()
{
    if (pwmCounter >= 255.0f) {
        pwmCounter = 0.0f;
    }
    if (pwmCounter < 20.0f) {
        pwmCounter += 0.2f;
    }
    else if (pwmCounter >= 20.0f && pwmCounter < 100.0f) {
        pwmCounter += 0.4f;
    }
    else {
        pwmCounter += 1.0f;
    }
}
