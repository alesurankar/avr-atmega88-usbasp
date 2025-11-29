#include <util/delay.h>
#include "Blinking.hpp"

// public section
Blinking::Blinking()
    :
    type(TYPE::BL1),
    blinkCounter(0),
    ledOn(false)
{
    led.setOutput();
}

void Blinking::Blink(TYPE type_in) {
    type = type_in;
}

void Blinking::Update() {
    switch(type) {
        case (TYPE::BL1):
            Prog1();
            break;
        case (TYPE::BL2):
            Prog2();
            break;
    }
    blinkCounter++;
    _delay_ms(1);
}

// private section
void Blinking::Prog1() {
    if(blinkCounter >= 100) {
        led.toggle();
        blinkCounter = 0;
    }
}

void Blinking::Prog2() {
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
}