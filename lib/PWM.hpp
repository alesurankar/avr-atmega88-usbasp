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
    void InitTimer(uint8_t duty)
    {
        if constexpr (PinT::port == 'D' && PinT::bit == 6) {
            Timer0A(duty);
        }
        else if constexpr (PinT::port == 'D' && PinT::bit == 5) {
            Timer0B(duty);
        }
        else if constexpr (PinT::port == 'B' && PinT::bit == 1) {
            Timer1A(duty);
        }
        else if constexpr (PinT::port == 'B' && PinT::bit == 2) {
            Timer1B(duty);
        }
        #if defined(__AVR_ATmega8__)
            else if constexpr (PinT::port == 'B' && PinT::bit == 3) {
                Timer2(duty);
            }
        #elif defined(__AVR_ATmega88__)
            else if constexpr (PinT::port == 'B' && PinT::bit == 3) {
                Timer2A(duty);
            }
            else if constexpr (PinT::port == 'B' && PinT::bit == 3) {
                Timer2B(duty);
            }
        #endif
        else static_assert(sizeof(PinT) == 0, "PWM: Unsupported pin");
    }
private:
    #if defined(__AVR_ATmega8__)
    #include "../include/timers/ATMega8_timers.hpp"
    #elif defined(__AVR_ATmega88__)
    #include "../include/timers/ATMega88_timers.hpp"
    #endif
};