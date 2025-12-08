#include <util/delay.h>
#include "Blinking.hpp"

// public section
Blinking::Blinking()
    :
    type(TYPE::BL1),
    blinkCounter(0),
    ledOn(false)
{
    led.SetAsOutput();
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
    if(blinkCounter >= 10) {
        led.ToggleState();
        blinkCounter = 0;
    }
}

void Blinking::Prog2() {
    if(blinkCounter <= 200) {
        if(blinkCounter <= 100) {
            if(!ledOn) {
                led.SetState(true);
                ledOn = true;
            }
        }
        else if (blinkCounter > 100 && blinkCounter <= 133) {
            if(ledOn) {
                led.SetState(false);
                ledOn = false;
            }
        }
        else if (blinkCounter > 133 && blinkCounter <= 166) {
            if(!ledOn) {
                led.SetState(true);
                ledOn = true;
            }
        }
        else {
            if(ledOn) {
                led.SetState(false);
                ledOn = false;
            }
        }
    }
    else {
        blinkCounter = 0;
    }
}