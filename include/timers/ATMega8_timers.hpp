/////////////////////////////////////////////
//                                         //
// this ATmega8 timer file is not complete // 
//                                         //
/////////////////////////////////////////////

static void Timer0A(uint8_t duty) {  //////////////// OC0A
    
}
static void Timer0B(uint8_t duty) {  //////////////// OC0B
    
}
static void Timer1A(uint8_t duty) {  //////////////// OC1A
    // Clear previous settings
    TCCR1A &= ~((1 << COM1A1) | (1 << COM1A0) | (1 << WGM11) | (1 << WGM10));
    TCCR1B &= ~(1 << WGM13 | 1 << WGM12 | 1 << CS12 | 1 << CS11 | 1 << CS10);
    // Set Fast PWM 8-bit, non-inverting mode
    TCCR1A |= (1 << COM1A1) | (1 << WGM10);  // WGM11=0, WGM10=1
    TCCR1B |= (1 << WGM12) | (1 << CS01) | (1 << CS00); // WGM12=1, Prescaler=64
    // Set duty cycle
    OCR1A = duty;
}
static void Timer1B(uint8_t duty) {  //////////////// OC1B
    // Clear previous settings
    TCCR1A &= ~((1 << COM1B1) | (1 << COM1B0) | (1 << WGM11) | (1 << WGM10));
    TCCR1B &= ~(1 << WGM13 | 1 << WGM12 | 1 << CS12 | 1 << CS11 | 1 << CS10);
    // Set Fast PWM 8-bit, non-inverting mode
    TCCR1A |= (1 << COM1B1) | (1 << WGM10);           // WGM11=0, WGM10=1
    TCCR1B |= (1 << WGM12) | (1 << CS01) | (1 << CS00); // WGM12=1, Prescaler=64
    // Set duty cycle
    OCR1B = duty;
}
static void Timer2(uint8_t duty) {  //////////////// OC2
    // Clear previous settings
    TCCR2 &= ~((1 << COM21) | (1 << COM20) | (1 << WGM21) | (1 << WGM20));
    TCCR2 &= ~( (1 << CS22) | (1 << CS21) | (1 << CS20) );
    // Set Fast PWM, non-inverting mode
    TCCR2 |= (1 << COM21) | (1 << WGM21) | (1 << WGM20); // Fast PWM 8-bit
    // Prescaler = 8
    TCCR2 &= ~(1 << CS22);
    TCCR2 |=  (1 << CS21);
    TCCR2 &= ~(1 << CS20);
    // Set duty cycle
    OCR2 = duty;
}