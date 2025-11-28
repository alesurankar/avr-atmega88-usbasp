#pragma once
#include <avr/io.h>

template<char PORT, uint8_t BIT>
class Pin
{
  public:
    static inline void setOutput()
    {
        ddr() |= (1 << BIT);
    }
    static inline void setInput()
    {
        ddr() &= ~(1 << BIT);
    }
    static inline void high()
    {
        port() |= (1 << BIT);
    }
    static inline void low()
    {
        port() &= ~(1 << BIT);
    }
    static inline void toggle()
    {
        port() ^= (1 << BIT);
    }
    static inline bool read()
    {
        return pinreg() & (1 << BIT);
    }
private:
    static constexpr volatile uint8_t& ddr()
    {
        if constexpr (PORT == 'B') return DDRB;
        else if constexpr (PORT == 'C') return DDRC;
        else return DDRD;
    }
    static constexpr volatile uint8_t& port()
    {
        if constexpr (PORT == 'B') return PORTB;
        else if constexpr (PORT == 'C') return PORTC;
        else return PORTD;
    }
    static constexpr volatile uint8_t& pinreg()
    {
        if constexpr (PORT == 'B') return PINB;
        else if constexpr (PORT == 'C') return PINC;
        else return PIND;
    }
};
