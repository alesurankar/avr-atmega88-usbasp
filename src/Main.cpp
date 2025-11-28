#include "Pin.hpp"
#include <util/delay.h>


int main()
{
  pin::pb3 led;
  pin::pd5 btn;

  led.setOutput();
  btn.setInput();

  while(1) {
    if(btn.read()) {
      led.high();
    }
    else {
      led.low();
    }

    for (int i = 0; i < 100; i++) {
      led.toggle();
      _delay_ms(100);
    }
  }
}