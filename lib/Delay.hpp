#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

volatile bool timerFlag = false;

template<uint8_t TIMER_NUM>
void Timer_Init_CTC_1ms()
{
    // Registers depend on timer number
    volatile uint8_t &TCCRA = CAT3(TCCR, TIMER_NUM, A);
    volatile uint8_t &TCCRB = CAT3(TCCR, TIMER_NUM, B);
    volatile uint8_t &OCR   = CAT3(OCR,  TIMER_NUM, A);
    volatile uint8_t &TIMSK = CAT3(TIMSK, TIMER_NUM, );

    // --- CTC MODE ---
    TCCRA = (1 << WGM01);           // WGM01 = 1 → CTC
    TCCRB = (1 << CS01) | (1 << CS00);  // Prescaler = 64

    // --- 1ms compare match (16MHz/64 → 250kHz → 1ms = 250 ticks) ---
    OCR = 249;

    // Enable interrupt
    TIMSK |= (1 << OCIE0A);   // Note: OCIE0A / OCIE1A / OCIE2A expand properly

    sei();
}

ISR(TIMER0_COMPA_vect) { timerFlag = true; }
ISR(TIMER1_COMPA_vect) { timerFlag = true; }
ISR(TIMER2_COMPA_vect) { timerFlag = true; }

void sleep_ms(uint16_t ms)
{
    for (uint16_t i = 0; i < ms; i++) {
        timerFlag = false;

        set_sleep_mode(SLEEP_MODE_IDLE);
        sleep_enable();
        sleep_cpu();    // sleeps until ISR fires
        sleep_disable();

        while (!timerFlag); // extra safety
    }
}