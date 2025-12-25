#pragma once
#include <avr/io.h>


class Adc
{
public:
    enum class Reference 
    {
        AREF  = 0,
        AVCC  = (1 << REFS0),
        INTERNAL_1V1 = (1 << REFS1) | (1 << REFS0)
    };
    void Init(Reference ref = Reference::AVCC)
    {
        // Set reference voltage
        ADMUX = static_cast<uint8_t>(ref);

        // Enable ADC, prescaler = 128 (16MHz → 125kHz, 8MHz → 62.5kHz)
        ADCSRA = (1 << ADEN)
            | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    }
    uint16_t Read(uint8_t channel)
    {
        channel &= 0x07; // limit to ADC0–ADC7

        // Select channel without touching reference bits
        ADMUX = (ADMUX & 0xF0) | channel;

        // Disable digital input on this ADC pin
        DIDR0 |= (1 << channel);

        // Start conversion
        ADCSRA |= (1 << ADSC);
        while (ADCSRA & (1 << ADSC));

        uint8_t low  = ADCL;
        uint8_t high = ADCH;

        return (high << 8) | low;
    }
uint16_t ToMillivolts(uint16_t adc, uint16_t vref_mv = 5000)
    {
        return (adc * vref_mv) / 1023;
    }
};