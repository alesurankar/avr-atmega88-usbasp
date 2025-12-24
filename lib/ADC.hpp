#include <avr/io.h>

void adc_init(uint8_t channel) {
    // Select AVcc as reference and choose channel
    ADMUX = (1 << REFS0) | (channel & 0x0F);

    // Disable digital input on selected channel
    DIDR0 |= (1 << channel);

    // Enable ADC and set prescaler 128 → ADC clock 62.5 kHz
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
} 

// Blocking read from ADC5
uint16_t adc_read() {
    ADCSRA |= (1 << ADSC);            // Start conversion

    while (ADCSRA & (1 << ADSC)) {}   // Wait until ADSC = 0

    uint8_t low  = ADCL;              // MUST read low first
    uint8_t high = ADCH;

    return (high << 8) | low;         // Combine 10-bit value
}

// Convert raw ADC to voltage in millivolts (mV)
uint16_t adc_to_millivolts(uint16_t adc_value) {
    // V = (ADC / 1023) * 5000 mV
    // multiplied first to avoid float
    return (adc_value * 5000UL) / 1023;
}


