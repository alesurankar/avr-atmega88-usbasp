#include "Blinking.hpp"

int main()
{
  Blinking b;
  pin::pd5 btn;

  while(1) {
    if(btn.read()) {
      b.Blink(Blinking::TYPE::BL1);
    }
    else {
      b.Blink(Blinking::TYPE::BL2);
    }
    b.Update();
  }
}