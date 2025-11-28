#include "Pin.hpp"
#include <util/delay.h>

using led = Pin<'B', 3>;
using btn = Pin<'D', 5>;

int main()
{
  led::setOutput();
  btn::setInput();
  
  while(1) {
    if (btn::read())
      led::high();
    else
      led::low();
    }
    _delay_ms(100);
}