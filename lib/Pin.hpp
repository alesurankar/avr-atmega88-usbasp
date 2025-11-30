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
          ddr() |= (1 << BIT);
      }
      static inline void SetInput()
      {
          ddr() &= ~(1 << BIT);
      }
      inline void High()
      {
          port() |= (1 << BIT);
      }
      inline void Low()
      {
          port() &= ~(1 << BIT);
      }
      inline void Toggle()
      {
          port() ^= (1 << BIT);
      }
      inline bool Read()
      {
          return pinreg() & (1 << BIT);
      }
  private:
      static inline volatile uint8_t& ddr()
      {
          if constexpr (PORT == 'B') return DDRB;
          else if constexpr (PORT == 'C') return DDRC;
          else if constexpr (PORT == 'D') return DDRD;
          else static_assert([] {return false; }(), "INVALID PORT: must be 'B', 'C', or 'D'");
      }
      static inline volatile uint8_t& port()
      {
          if constexpr (PORT == 'B') return PORTB;
          else if constexpr (PORT == 'C') return PORTC;
          else if constexpr (PORT == 'D') return PORTD;
          else static_assert([] {return false; }(), "INVALID PORT: must be 'B', 'C', or 'D'");
      }
      static inline volatile uint8_t& pinreg()
      {
          if constexpr (PORT == 'B') return PINB;
          else if constexpr (PORT == 'C') return PINC;
          else if constexpr (PORT == 'D') return PORTD;
          else static_assert([] {return false; }(), "INVALID PORT: must be 'B', 'C', or 'D'");
      }
  };

  // MCU-specific aliases
  #if defined(__AVR_ATmega8__)
  #include "../include/ATMega8_pins.hpp"
  #elif defined(__AVR_ATmega88__)
  #include "../include/ATMega88_pins.hpp"
  #elif defined(__AVR_ATmega32__)
  #include "../include/ATMega32_pins.hpp"
  #endif
}