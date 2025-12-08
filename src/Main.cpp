//#include "Counter.h"
#include "../lib/Pin.hpp"
#include "../lib/PWM.hpp"
#include <util/delay.h>
//#include "../lib/Delay.hpp"

int main()
{
  static constexpr uint16_t DEBOUNCE_COUNT = 100;
  static uint16_t debounceCounter = 0;
  //Counter count;
  int i = 0;
  bool btn1Pressed = false;
  bool btn2Pressed = false;
  pin::pc4 btn1;
  pin::pc5 btn2;
  pin::pd6 bit1;
  btn1.SetAsInput();
  btn2.SetAsInput();
  bit1.SetAsOutput();
  while(1) {

    
//////////////////////////////////////////////////////////////////////////////////
// naslednja stvar je da naredim custom sleep delay, za 60 cps(cycle per second)//
//////////////////////////////////////////////////////////////////////////////////



    i++;
    static int maxCycles = 1;
    if (i >= maxCycles) {
      bit1.ToggleState();
      i = 0;
    }
    if (btn1.ReadState()) {
        if (!btn1Pressed) {
            btn1Pressed = true;
            maxCycles += 1;
        }
    }
    else {
        btn1Pressed = false;
    }
    if (btn2.ReadState()) {
        if (!btn2Pressed) {
            btn2Pressed = true;
            maxCycles -= 1;
        }
    }
    else {
        btn2Pressed = false;
    }
    _delay_ms(100);
  }
}