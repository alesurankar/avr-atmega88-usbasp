#pragma once
#include <avr/io.h>

namespace pin
{
  template<char PORT, uint8_t BIT>
  class Pin
  {
    public:
      inline void setOutput()
      {
          ddr() |= (1 << BIT);
      }
      inline void setInput()
      {
          ddr() &= ~(1 << BIT);
      }
      inline void high()
      {
          port() |= (1 << BIT);
      }
      inline void low()
      {
          port() &= ~(1 << BIT);
      }
      inline void toggle()
      {
          port() ^= (1 << BIT);
      }
      inline bool read()
      {
          return pinreg() & (1 << BIT);
      }
  private:
      static inline volatile uint8_t& ddr()
      {
          if constexpr (PORT == 'B') return DDRB;
          else if constexpr (PORT == 'C') return DDRC;
          else return DDRD;
      }
      static inline volatile uint8_t& port()
      {
          if constexpr (PORT == 'B') return PORTB;
          else if constexpr (PORT == 'C') return PORTC;
          else return PORTD;
      }
      static inline volatile uint8_t& pinreg()
      {
          if constexpr (PORT == 'B') return PINB;
          else if constexpr (PORT == 'C') return PINC;
          else return PIND;
      }
  };

  using pb1 = Pin<'B', 1>;
  using pb2 = Pin<'B', 2>;
  using pb3 = Pin<'B', 3>;
  using pb4 = Pin<'B', 4>;
  using pb5 = Pin<'B', 5>;
  using pb6 = Pin<'B', 6>;
  using pb7 = Pin<'B', 7>;
  using pc1 = Pin<'C', 1>;
  using pc2 = Pin<'C', 2>;
  using pc3 = Pin<'C', 3>;
  using pc4 = Pin<'C', 4>;
  using pc5 = Pin<'C', 5>;
  using pc6 = Pin<'C', 6>;
  using pc7 = Pin<'C', 7>;
  using pd1 = Pin<'D', 1>;
  using pd2 = Pin<'D', 2>;
  using pd3 = Pin<'D', 3>;
  using pd4 = Pin<'D', 4>;
  using pd5 = Pin<'D', 5>;
  using pd6 = Pin<'D', 6>;
  using pd7 = Pin<'D', 7>;
}