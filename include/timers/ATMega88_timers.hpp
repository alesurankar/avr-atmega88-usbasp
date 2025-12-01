public:
    void InitTimer(uint8_t duty)
    {
        if constexpr (PinT::port == 'B' && PinT::bit == 1) {
            Timer1A(duty);
        }
        else if constexpr (PinT::port == 'B' && PinT::bit == 2) {
            Timer1B(duty);
        }
        else if constexpr (PinT::port == 'B' && PinT::bit == 3) {
            Timer2A(duty);
        }
        else if constexpr (PinT::port == 'D' && PinT::bit == 3) {
            Timer2B(duty);
        }
        else if constexpr (PinT::port == 'D' && PinT::bit == 5) {
            Timer0B(duty);
        }
        else if constexpr (PinT::port == 'D' && PinT::bit == 6) {
            Timer0A(duty);
        }
        else static_assert(sizeof(PinT) == 0, "PWM: Unsupported pin");
    }
private:
    static void Timer1A(uint8_t duty) {  //////////////// OCR1A
        // Clear previous settings
        TCCR1A &= ~((1 << COM1A1) | (1 << COM1A0) | (1 << WGM11) | (1 << WGM10));
        TCCR1B &= ~(1 << WGM13 | 1 << WGM12 | 1 << CS12 | 1 << CS11 | 1 << CS10);
        // Set Fast PWM 8-bit, non-inverting mode
        TCCR1A |= (1 << COM1A1) | (1 << WGM10);  // WGM11=0, WGM10=1
        TCCR1B |= (1 << WGM12) | (1 << CS01) | (1 << CS00); // WGM12=1, Prescaler=64
        // Set duty cycle
        OCR1A = duty;
    }
    static void Timer1B(uint8_t duty) {  //////////////// OCR1B
        // Clear previous settings
        TCCR1A &= ~((1 << COM1B1) | (1 << COM1B0) | (1 << WGM11) | (1 << WGM10));
        TCCR1B &= ~(1 << WGM13 | 1 << WGM12 | 1 << CS12 | 1 << CS11 | 1 << CS10);
        // Set Fast PWM 8-bit, non-inverting mode
        TCCR1A |= (1 << COM1B1) | (1 << WGM10);           // WGM11=0, WGM10=1
        TCCR1B |= (1 << WGM12) | (1 << CS01) | (1 << CS00); // WGM12=1, Prescaler=64
        // Set duty cycle
        OCR1B = duty;
    }
    static void Timer2A(uint8_t duty) {  //////////////// OCR2A
        // Clear previous settings
        TCCR2A &= ~((1 << COM2A1) | (1 << COM2A0) | (1 << WGM21) | (1 << WGM20));
        TCCR2B &= ~(1 << CS22 | 1 << CS21 | 1 << CS20 | (1 << WGM22));
        // Set Fast PWM, non-inverting mode
        TCCR2A |= (1 << COM2A1) | (1 << WGM21) | (1 << WGM20); // Fast PWM 8-bit
        TCCR2B |= (1 << CS21);                                 // Prescaler = 8
        // Set duty cycle
        OCR2A = duty;
    }
    static void Timer2B(uint8_t duty) {  //////////////// OCR2B
        // Clear previous settings
        TCCR2A &= ~((1 << COM2B1) | (1 << COM2B0) | (1 << WGM21) | (1 << WGM20));
        TCCR2B &= ~(1 << CS22 | 1 << CS21 | 1 << CS20 | (1 << WGM22));
        // Set Fast PWM, non-inverting mode
        TCCR2A |= (1 << COM2B1) | (1 << WGM21) | (1 << WGM20); // Fast PWM 8-bit
        TCCR2B |= (1 << CS21);                                 // Prescaler = 8
        // Set duty cycle
        OCR2B = duty;
    }
    static void Timer0B(uint8_t duty) {  //////////////// OCR0B
        // Clear previous settings
        TCCR0A &= ~((1 << COM0B1) | (1 << COM0B0) | (1 << WGM01) | (1 << WGM00));
        TCCR0B &= ~(1 << CS02 | 1 << CS01 | 1 << CS00 | (1 << WGM02));
        // Set Fast PWM, non-inverting mode
        TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00); // Fast PWM 8-bit
        TCCR0B |= (1 << CS01) | (1 << CS00);                   // Prescaler = 64
        // Set duty cycle
        OCR0B = duty;
    }
    static void Timer0A(uint8_t duty) {  //////////////// OCR0A
       // Clear previous settings
        TCCR0A &= ~((1 << COM0A1) | (1 << COM0A0) | (1 << WGM01) | (1 << WGM00));
        TCCR0B &= ~(1 << CS02 | 1 << CS01 | 1 << CS00 | (1 << WGM02));
        // Set Fast PWM, non-inverting mode
        TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // Fast PWM 8-bit
        TCCR0B |= (1 << CS01) | (1 << CS00);                   // Prescaler = 64
        // Set duty cycle
        OCR0A = duty;
    }