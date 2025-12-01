public:
    void InitTimer(uint8_t duty)
    {
        // if constexpr (PinT::port == 'B' && PinT::bit == 3) {
        //     Timer0_PB3(duty);
        // }
        // else if constexpr (PinT::port == 'B' && PinT::bit == 4) {
        //     Timer0_PB4(duty);
        // }
        // else if constexpr (PinT::port == 'D' && PinT::bit == 4) {
        //     Timer1_PD4(duty);
        // }
        // else if constexpr (PinT::port == 'D' && PinT::bit == 5) {
        //     Timer1_PD5(duty);
        // }
        // else if constexpr (PinT::port == 'D' && PinT::bit == 7) {
        //     Timer2_PD7(duty);
        // }
        // else static_assert(sizeof(PinT) == 0, "PWM: Unsupported pin");
    }
private:
    // static void Timer0_PB3(uint8_t duty) {  //////////////// Timer0 OC0A
    //     TCCR0A &= ~((1 << COM0A1) | (1 << COM0A0));
    //     TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
    //     TCCR0B |= (1 << CS01) | (1 << CS00);
    //     OCR0A = duty;
    // }
    // static void Timer0_PB4(uint8_t duty) {  //////////////// Timer0 OC0B
    //     TCCR0A &= ~((1 << COM0B1) | (1 << COM0B0));
    //     TCCR0A |= (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);
    //     TCCR0B |= (1 << CS01) | (1 << CS00);
    //     OCR0B = duty;
    // }
    // static void Timer1_PD4(uint8_t duty) {  //////////////// Timer1 OC1B
    //     TCCR1A &= ~((1 << COM1B1) | (1 << COM1B0));
    //     TCCR1A |= (1 << COM1B1) | (1 << WGM10);
    //     TCCR1B |= (1 << WGM12) | (1 << CS11);
    //     OCR1B = duty;
    // }
    // static void Timer1_PD5(uint8_t duty) {  //////////////// Timer1 OC1A
    //     TCCR1A &= ~((1 << COM1A1) | (1 << COM1A0));
    //     TCCR1A |= (1 << COM1A1) | (1 << WGM10);
    //     TCCR1B |= (1 << WGM12) | (1 << CS11);
    //     OCR1A = duty;
    // }
    // static void Timer2_PD7(uint8_t duty) {  //////////////// Timer2 OC2
    //     TCCR2 &= ~((1 << COM21) | (1 << COM20));
    //     TCCR2 |= (1 << COM21) | (1 << WGM20) | (1 << WGM21);
    //     TCCR2 |= (1 << CS22);
    //     OCR2 = duty;
    }