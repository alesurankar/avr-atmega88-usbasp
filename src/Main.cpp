//#include "Counter.h"
#include "../lib/Pin.hpp"
//#include "../lib/PWM.hpp"
//#include <util/delay.h>
#include "../lib/Delay.hpp"

int main()
{
  //pin::pc4 btn1;
  //pin::pc5 btn2;
  pin::pd6 bit1;
  bit1.SetAsOutput();
  delay::Timer2_Setup();
  while(1) {
    bit1.ToggleState();
    delay::sleep_ms(500); 
  }
}