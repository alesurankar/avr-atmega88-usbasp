#include "Pin.hpp"


Pin::Pin(uint8_t pin_in)
    :
    pin(pin_in)
{}

void Pin::SetInput() {
    GetDDR() &= ~(1 << pin);
}

void Pin::SetOutput() {
    GetDDR() |= (1 << pin);
}

void Pin::SetHigh() {
    GetPORT() |= (1 << pin);
}

void Pin::SetLow() {
    GetPORT() &= ~(1 << pin);
}

void Pin::Toggle() {
    GetPORT() ^= (1 << pin);
}

volatile uint8_t& Pin::GetDDR() {
    if (pin <= PB7) {
      return DDRB;
    }
    else if (pin >= PC0 && pin <= PC6) {
      return DDRB;
    }
    else {
      return DDRD;
    }
}

volatile uint8_t& Pin::GetPORT() {
    if (pin <= PB7) {
        return PORTB;
    }
    else if (pin >= PC0 && pin <= PC6) {
        return PORTB;
    }
    else {
        return PORTD;
    }
}