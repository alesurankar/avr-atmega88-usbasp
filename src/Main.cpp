#include "Blinking.hpp"
#include "../lib/PWM.hpp"



int main()
{
  PWM<pin::pb3> pwm(128);
  Blinking b;
  pin::pd5 btn;

  while(1) {
    if(btn.Read()) {
      b.Blink(Blinking::TYPE::BL1);
    }
    else {
      b.Blink(Blinking::TYPE::BL2);
    }
    b.Update();
  }
}