#pragma once
#include "Pin.hpp"
#include <avr/io.h>

template<typename PinT>
class PWM
{
public:
    PWM(uint8_t duty = 128) {

    }
    // PWM(uint8_t) {
    //     static_assert(sizeof(PinT) == 0, "PWM: Unsupported pin");
    // }
    // template<> struct PWM<pin::pb3>
    // PWM(uint8_t duty) { 
    //     PWM_Timer::InitTimer0_PB3_FastPWM(duty); 
    // }
    // template<> struct PWM<pin::pb4>
    // PWM(uint8_t duty) { 
    //     PWM_Timer::InitTimer0_PB4_FastPWM(duty); 
    // }
    // template<> struct PWM<pin::pd4>
    // PWM(uint8_t duty) { 
    //     PWM_Timer::InitTimer1_PD4_FastPWM(duty); 
    // }
    // template<> struct PWM<pin::pd5>
    // PWM(uint8_t duty) { 
    //     PWM_Timer::InitTimer1_PD5_FastPWM(duty); 
    // }
    // template<> struct PWM<pin::pd7>
    // PWM(uint8_t duty) { 
    //     PWM_Timer::InitTimer2_PD7_FastPWM(duty); 
    // }
private:
    static void InitTimer0_PB3_FastPWM(uint8_t duty) {  //////////////// Timer0 OC0A
        TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
        TCCR0B = (1 << CS01) | (1 << CS00);
        OCR0A = duty;
    }
    static void InitTimer0_PB4_FastPWM(uint8_t duty) {  //////////////// Timer0 OC0B
        TCCR0A = (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);
        TCCR0B = (1 << CS01) | (1 << CS00);
        OCR0B = duty;
    }
    static void InitTimer1_PD4_FastPWM(uint8_t duty) {  //////////////// Timer1 OC1B
        TCCR1A = (1 << COM1B1) | (1 << WGM10);
        TCCR1B = (1 << WGM12) | (1 << CS11);
        OCR1B = duty;
    }
    static void InitTimer1_PD5_FastPWM(uint8_t duty) {  //////////////// Timer1 OC1A
        TCCR1A = (1 << COM1A1) | (1 << WGM10);
        TCCR1B = (1 << WGM12) | (1 << CS11);
        OCR1A = duty;
    }
    static void InitTimer2_PD7_FastPWM(uint8_t duty) {  //////////////// Timer2 OC2
        TCCR2A = (1 << COM2A0) | (1 << WGM20) | (1 << WGM21);
        TCCR2A |= (1 << CS22);
        OCR2A = duty;
    }
};