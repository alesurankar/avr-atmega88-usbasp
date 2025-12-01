#pragma once
#include "../lib/Pin.hpp"
#include <avr/io.h>


template<typename PinT>
class PWM
{
public:
    PWM() 
    {
        PinT::SetOutput();
    }
    #if defined(__AVR_ATmega8__)
    #include "../include/timers/ATMega8_timers.hpp"
    #elif defined(__AVR_ATmega88__)
    #include "../include/timers/ATMega88_timers.hpp"
    #endif
};