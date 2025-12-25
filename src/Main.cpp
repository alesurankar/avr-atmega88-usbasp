#include "../lib/Pin.hpp"
#include "../lib/Adc.hpp"
#include "../lib/UART.hpp"
#include "../lib/Delay.hpp"

pin::pd5 bit1;
pin::pd6 bit2;
pin::pd7 bit3;
pin::pd2 adcSwitch;
UART uart;
Delay delay;
Delay timeChacker;
Adc adc;

void SetPinState(bool pin1, bool pin2, bool pin3); 

int main()
{
  bit1.SetAsOutput();
  bit2.SetAsOutput();
  bit3.SetAsOutput();
  adcSwitch.SetAsOutput();
  uart.Init();
  adc.Init();
  int freq = 1;
  int lines = 0;

  while(1) {
    uint32_t dt = timeChacker.Mark();
    adcSwitch.SetState(true);
    delay.Delay_ms(1);
    uint16_t raw = adc.Read(5);
    adcSwitch.SetState(false);

    if (raw <= 150) {
      SetPinState(false, false, false);
      freq = 1;
    }
    else if (raw > 125 && raw <= 250) {
      SetPinState(true, false, false);
      freq = 2;
    }
    else if (raw > 250 && raw <= 375) {
      SetPinState(false, true, false);
      freq = 3;
    }
    else if (raw > 375 && raw <= 500) {
      SetPinState(true, true, false);
      freq = 4;
    }
    else if (raw > 000 && raw <= 625) {
      SetPinState(false, false, true);
      freq = 5;
    }
    else if (raw > 625 && raw <= 750) {
      SetPinState(true, false, true);
      freq = 6;
    }
    else if (raw > 750 && raw <= 875) {
      SetPinState(false, true, true);
      freq = 7;
    }
    else if (raw > 875) {
      SetPinState(true, true, true);
      freq = 8;
    }

    if(lines > 9) {
      uart.Clear();
      lines = 0;
    }
    uart.SendString("frequency = ");
    uart.SendUint(freq);
    uart.NewLine();
    uart.SendString("cycle time: ");
    uart.SendUint(dt);
    uart.NewLine();
    lines++;
    delay.MaxFreq(freq);
  }
}

void SetPinState(bool pin1, bool pin2, bool pin3)
{
      bit1.SetState(pin1);
      bit2.SetState(pin2);
      bit3.SetState(pin3);
}