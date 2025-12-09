#pragma once
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

namespace delay
{
    volatile bool timerFlag = false;

    ISR(TIMER2_COMPA_vect) 
    {
        timerFlag = true;
    }

    void Timer2_Setup()
    {
        TCCR2A = (1 << WGM21);  // CTC
        TCCR2B = 0;             // stopped
        TIMSK2 = (1 << OCIE2A); // enable interrupt
        PRR |= (1 << PRADC) | (1 << PRTIM0) | (1 << PRTIM1); 
        sei();
    }

    inline void sleep_ms(uint32_t ms)
    {
        // Timer prescaler
        const uint16_t prescaler = 1024;

        // tick_ms = milliseconds per timer tick (integer math)
        const uint32_t tick_us = (prescaler * 1000000UL) / F_CPU;

        // Max chunk in microseconds (Timer2 max = 255 ticks)
        const uint32_t max_chunk_us = tick_us * 255;

        while (ms > 0) {
            uint32_t chunk_ms = (ms > (max_chunk_us / 1000UL)) ? (max_chunk_us / 1000UL) : ms;
            ms -= chunk_ms;

            // Convert chunk to OCR ticks
            uint16_t chunk_us = chunk_ms * 1000UL;
            uint8_t ocr = (chunk_us + tick_us - 1) / tick_us; // ceil division
            if (ocr == 0) {
                ocr = 1;
            } 

            timerFlag = false;
            OCR2A = ocr;

            // Start Timer2 with prescaler 1024
            TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20);

            // Sleep in Power-save mode
            set_sleep_mode(SLEEP_MODE_PWR_SAVE);
            sleep_enable();
            sleep_cpu();
            sleep_disable();

            while (!timerFlag);  // wait until timer ISR sets flag

            // Stop timer
            TCCR2B = 0;
        }
    }
}