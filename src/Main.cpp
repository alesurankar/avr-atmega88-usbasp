#include "Blinking.hpp"
#include "../lib/PWM.hpp"

int main()
{
  PWM<pin::pd5> pwm1;
  pwm1.InitTimer();
  // Blinking b;
   pin::pd7 btn;
   btn.SetInput();

  float pwmCounter = 0.0f;
  while(1) {
     if(btn.Read()) {
         if (pwmCounter < 1.0f) {
           pwmCounter = 255.0f;
        }
        if (pwmCounter > 100.0f) {
          pwmCounter -= 0.1f;
        }
        else if (pwmCounter >= 20.0f && pwmCounter < 100.0f) {
          pwmCounter -= 0.05f;
        }
        else {
          pwmCounter -= 0.02f;
        }
    //   b.Blink(Blinking::TYPE::BL1);
     }
     else {
        if (pwmCounter >= 255.0f) {
          pwmCounter = 0.0f;
        }
        if (pwmCounter < 20.0f) {
          pwmCounter += 0.01f;
        }
        else if (pwmCounter >= 20.0f && pwmCounter < 100.0f) {
          pwmCounter += 0.02f;
        }
        else {
          pwmCounter += 0.04f;
        }
        //   b.Blink(Blinking::TYPE::BL2);
     }
    // b.Update();
    
    pwm1.SetDutyCycle((int)pwmCounter);
  }
}