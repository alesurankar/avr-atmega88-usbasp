#pragma once
#include <avr/io.h>

namespace pin
{
    template<char PORT, uint8_t BIT>
    class Pin
    {
    public:
        static inline void SetOutput()
        {
            Ddr() |= (1 << BIT);
        }
        static inline void SetInput()
        {
            Ddr() &= ~(1 << BIT);
        }
        inline void High()
        {
            Port() |= (1 << BIT);
        }
        inline void Low()
        {
            Port() &= ~(1 << BIT);
        }
        inline void Toggle()
        {
            Port() ^= (1 << BIT);
        }
        inline bool Read()
        {
            return PinReg() & (1 << BIT);
        }
    private:
        static inline volatile uint8_t& Ddr()
        {
            if constexpr (PORT == 'B') return DDRB;
            else if constexpr (PORT == 'C') return DDRC;
            else if constexpr (PORT == 'D') return DDRD;
            else static_assert([] {return false; }(), "INVALID PORT: must be 'B', 'C', or 'D'");
        }
        static inline volatile uint8_t& Port()
        {
            if constexpr (PORT == 'B') return PORTB;
            else if constexpr (PORT == 'C') return PORTC;
            else if constexpr (PORT == 'D') return PORTD;
            else static_assert([] {return false; }(), "INVALID PORT: must be 'B', 'C', or 'D'");
        }
        static inline volatile uint8_t& PinReg()
        {
            if constexpr (PORT == 'B') return PINB;
            else if constexpr (PORT == 'C') return PINC;
            else if constexpr (PORT == 'D') return PORTD;
            else static_assert([] {return false; }(), "INVALID PORT: must be 'B', 'C', or 'D'");
        }
    public:
        static constexpr uint8_t bit = BIT;
        static constexpr char port = PORT;
    };

    // MCU-specific aliases
    #if defined(__AVR_ATmega8__)
    #include "../include/pins/ATMega8_pins.hpp"
    #elif defined(__AVR_ATmega88__)
    #include "../include/pins/ATMega88_pins.hpp"
    #endif
}