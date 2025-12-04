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
    void InitTimer()
    {
        uint8_t duty = 255;
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
        #elif defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__)
            else if constexpr (PinT::port == 'B' && PinT::bit == 3) {
                Timer2A(duty);
            }
            else if constexpr (PinT::port == 'B' && PinT::bit == 3) {
                Timer2B(duty);
            }
        #endif
        else static_assert(sizeof(PinT) == 0, "PWM: Unsupported pin");
    }
    void SetDutyCycle(uint8_t duty) 
    {
         if constexpr (PinT::port == 'D' && PinT::bit == 6) {
            SetDutyCycle0A(duty);
        }
        else if constexpr (PinT::port == 'D' && PinT::bit == 5) {
            SetDutyCycle0B(duty);
        }
        else if constexpr (PinT::port == 'B' && PinT::bit == 1) {
            SetDutyCycle1A(duty);
        }
        else if constexpr (PinT::port == 'B' && PinT::bit == 2) {
            SetDutyCycle1B(duty);
        }
        #if defined(__AVR_ATmega8__)
            else if constexpr (PinT::port == 'B' && PinT::bit == 3) {
                SetDutyCycle2(duty);
            }
        #elif defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__)
            else if constexpr (PinT::port == 'B' && PinT::bit == 3) {
                SetDutyCycle02A(duty);
            }
            else if constexpr (PinT::port == 'B' && PinT::bit == 3) {
                SetDutyCycle2B(duty);
            }
        #endif
        else static_assert(sizeof(PinT) == 0, "PWM: Unsupported pin");
    }
private:
private:
    #if defined(__AVR_ATmega8__)
    #include "../include/timers/ATMega8_timers.hpp"
    #elif defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__)
    #include "../include/timers/ATMega168_timers.hpp"
    #endif
};