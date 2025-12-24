//#include "Counter.h"
#include "../lib/Pin.hpp"
#include "../lib/PWM.hpp"
#include "../lib/Delay.hpp"
#include "../lib/ADC.hpp"
#include "util/delay.h"
#include "uart.h"

pin::pd5 bit1;
pin::pd6 bit2;
pin::pd7 bit3;
pin::pd2 adcSwitch;
//pwm::pb3 m1;
UART uart;

void SetPinState(bool pin1, bool pin2, bool pin3); 

int main()
{
  uart.uart_init();
  //pin::pc4 btn1;
  //pin::pc5 btn2;
  adc_init(5);
  bit1.SetAsOutput();
  bit2.SetAsOutput();
  bit3.SetAsOutput();
  adcSwitch.SetAsOutput();
  delay::Timer2_Setup();
  int freq = 1;
  //bool motor = false;
  //int pwmCount = 0;
  
  int num = 0;
  while(1) {
    adcSwitch.SetState(true);
    _delay_ms(1);
    uint16_t raw = adc_read();
    adcSwitch.SetState(false);

    if (raw <= 150) {
      SetPinState(false, false, false);
    //  motor = false;
    }
    else if (raw > 125 && raw <= 250) {
      SetPinState(true, false, false);
    }
    else if (raw > 250 && raw <= 375) {
      SetPinState(false, true, false);
    }
    else if (raw > 375 && raw <= 500) {
      SetPinState(true, true, false);
    }
    else if (raw > 000 && raw <= 625) {
      SetPinState(false, false, true);
    }
    else if (raw > 625 && raw <= 750) {
      SetPinState(true, false, true);
    }
    else if (raw > 750 && raw <= 875) {
      SetPinState(false, true, true);
    }
    else if (raw > 875) {
      SetPinState(true, true, true);
    //  motor = true;
    }

    //if (motor) {
    //  pwmCount++;
    //}
    //else {
    //  pwmCount = 0;
    //}

    //if (pwmCount >= 255) {
    //  pwmCount = 0;
    //}
    //m1.SetDutyCycle(0);

    if(num > 9) {
      uart.send_string("\033[2J\033[H"); // Clear screen & move cursor home
      num = 0;
    }
    uart.send_string("num = ");
    uart.send_int(num);
    uart.new_line();
    num++;
    delay::MaxFreq(freq);
  }
}

void SetPinState(bool pin1, bool pin2, bool pin3)
{
      bit1.SetState(pin1);
      bit2.SetState(pin2);
      bit3.SetState(pin3);
}