#include "Pin.hpp"

int main()
{

  while(1) {
    Pin pin(PB3);
    pin.SetInput();

    _delay_ms(500);
  }
}