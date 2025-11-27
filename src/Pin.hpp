#pragma once
#include <avr/io.h>
#include <util/delay.h>

class Pin
{
public:
  Pin(uint8_t pin_in);
  void SetInput();
  void SetOutput();
  void SetHigh();
  void SetLow();
  void Toggle();
private:
  volatile uint8_t& GetDDR();
  volatile uint8_t& GetPORT();
private:
  uint8_t pin;
};
