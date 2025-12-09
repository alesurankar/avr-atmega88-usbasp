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
  int freq = 60;
  while(1) {
    static int a = 0;
    a++;
    if(a == freq) {
      bit1.ToggleState();
      a = 0;
    }


    delay::MaxFreq(freq);
  }
}