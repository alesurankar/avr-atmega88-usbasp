#include "Blinking.hpp"

int main()
{
  Blinking b;
  pin::pd5 btn;

  while(1) {
    if(btn.read()) {
      b.Blink1();
    }
    else {
      b.Blink2();
    }
    b.Update();
  }
}