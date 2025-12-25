#pragma once
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/wdt.h>


namespace dly
{
    inline volatile bool timerFlag = false;
    inline volatile bool wdtFlag = false;
    inline volatile uint32_t ms_counter = 0;
}

ISR(TIMER2_COMPA_vect) 
{
    dly::timerFlag = true;
    dly::ms_counter++;
}

ISR(WDT_vect) {
    dly::wdtFlag = true;
    dly::ms_counter += 16; // WDT tick ≈16 ms
}

class Delay
{
public:
    void Delay_ms(uint32_t ms)
    {
        uint32_t timer2_part = ms % 16;
        uint32_t wdt_part = ms - timer2_part;

        Sleep_ms(wdt_part);     // low-power sleep for multiples of 16 ms
        Wait_ms(timer2_part);   // precise remainder (<16 ms)
    }
    uint32_t Mark()
    {
        static uint32_t last_ms = 0;
        uint32_t now = dly::ms_counter;
        uint32_t delta = now - last_ms;
        last_ms = now;
        return delta;
    }
    void MaxFreq(uint32_t frequency) // max 1000Hz, min 1Hz
    {
        uint32_t dt_ms = Mark();
        uint32_t dt_us = 1000 * dt_ms;
        uint32_t wantedCycleTime_us = 1000000 / frequency;
        if(dt_us < wantedCycleTime_us) {
            const uint32_t neededSleepTime = (wantedCycleTime_us - dt_us) / 1000;
            Delay_ms(neededSleepTime);
        }
    }
private:
    void WDT_Init() 
    {
        cli(); // disable interrupts
        MCUSR &= ~(1 << WDRF);    // clear reset flag
        wdt_reset();

        // start timed configuration sequence
        WDTCSR |= (1 << WDCE) | (1 << WDE);

        // enable WDT interrupt, set prescaler to ~16 ms (1/64s)
        WDTCSR = (1 << WDIE) | (1 << WDP0);
        sei(); // enable interrupts
    }
    void Timer2_Init()
    {
        TCCR2A = (1 << WGM21);  // CTC
        TCCR2B = 0;             // stopped
        TIMSK2 = (1 << OCIE2A); // enable interrupt
        sei();
    }
    inline void Sleep_ms(uint32_t ms)  //16ms resolution, WDT low power
    {
        static bool wdt_init = false;
        if(!wdt_init) {
            WDT_Init();
            wdt_init = true;
        }
        const uint32_t tick_ms = 16;
        while(ms > 0) {
            dly::wdtFlag = false;

            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_cpu();
            sleep_disable();

            if(dly::wdtFlag) {
                ms = (ms > tick_ms) ? ms - tick_ms : 0;
            }
        }
    }
    inline void Wait_ms(uint32_t ms) //Timer2 based
    {
        static bool timer2_init = false;
        if(!timer2_init) {
            Timer2_Init();
            timer2_init = true;
        }
        const uint16_t prescaler = 1024;
        const uint32_t tick_us = (prescaler * 1000000UL) / F_CPU;
        const uint32_t max_chunk_us = tick_us * 255;

        while (ms > 0) {
            uint32_t chunk_ms = (ms > (max_chunk_us / 1000UL)) ? (max_chunk_us / 1000UL) : ms;
            ms -= chunk_ms;

            uint16_t chunk_us = chunk_ms * 1000UL;
            uint8_t ocr = (chunk_us + tick_us - 1) / tick_us;
            if (ocr == 0) {
                ocr = 1;
            } 

            dly::timerFlag = false;
            OCR2A = ocr;
            TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20);

            set_sleep_mode(SLEEP_MODE_IDLE);
            sleep_enable();
            sleep_cpu();
            sleep_disable();

            while (!dly::timerFlag);
            TCCR2B = 0;
        }
    }
};