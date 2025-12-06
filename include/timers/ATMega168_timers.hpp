
static void Timer0A() {  //////////////// OCR0A
    // Clear previous settings
    TCCR0A &= ~((1 << COM0A1) | (1 << COM0A0) | (1 << WGM01) | (1 << WGM00));
    TCCR0B &= ~(1 << CS02 | 1 << CS01 | 1 << CS00 | (1 << WGM02));
    // Set Fast PWM, non-inverting mode
    TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // Fast PWM 8-bit
    TCCR0B |= (1 << CS01) | (1 << CS00);                   // Prescaler = 64
    // Set duty cycle
    OCR0A = 255;
}
static void Timer0B() {  //////////////// OCR0B
    // Clear previous settings
    TCCR0A &= ~((1 << COM0B1) | (1 << COM0B0) | (1 << WGM01) | (1 << WGM00));
    TCCR0B &= ~(1 << CS02 | 1 << CS01 | 1 << CS00 | (1 << WGM02));
    // Set Fast PWM, non-inverting mode
    TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00); // Fast PWM 8-bit
    TCCR0B |= (1 << CS01) | (1 << CS00);                   // Prescaler = 64
    // Set duty cycle
    OCR0B = 255;
}
static void Timer1A() {  //////////////// OCR1A
    // Clear previous settings
    TCCR1A &= ~((1 << COM1A1) | (1 << COM1A0) | (1 << WGM11) | (1 << WGM10));
    TCCR1B &= ~(1 << WGM13 | 1 << WGM12 | 1 << CS12 | 1 << CS11 | 1 << CS10);
    // Set Fast PWM 8-bit, non-inverting mode
    TCCR1A |= (1 << COM1A1) | (1 << WGM10);  // WGM11=0, WGM10=1
    TCCR1B |= (1 << WGM12) | (1 << CS01) | (1 << CS00); // WGM12=1, Prescaler=64
    // Set duty cycle
    OCR1A = 65535;
}
static void Timer1B() {  //////////////// OCR1B
    // Clear previous settings
    TCCR1A &= ~((1 << COM1B1) | (1 << COM1B0) | (1 << WGM11) | (1 << WGM10));
    TCCR1B &= ~(1 << WGM13 | 1 << WGM12 | 1 << CS12 | 1 << CS11 | 1 << CS10);
    // Set Fast PWM 8-bit, non-inverting mode
    TCCR1A |= (1 << COM1B1) | (1 << WGM10);           // WGM11=0, WGM10=1
    TCCR1B |= (1 << WGM12) | (1 << CS01) | (1 << CS00); // WGM12=1, Prescaler=64
    // Set duty cycle
    OCR1B = 65535;
}
static void Timer2A() {  //////////////// OCR2A
    // Clear previous settings
    TCCR2A &= ~((1 << COM2A1) | (1 << COM2A0) | (1 << WGM21) | (1 << WGM20));
    TCCR2B &= ~(1 << CS22 | 1 << CS21 | 1 << CS20 | (1 << WGM22));
    // Set Fast PWM, non-inverting mode
    TCCR2A |= (1 << COM2A1) | (1 << WGM21) | (1 << WGM20); // Fast PWM 8-bit
    TCCR2B |= (1 << CS21);                                 // Prescaler = 8
    // Set duty cycle
    OCR2A = 255;
}
static void Timer2B() {  //////////////// OCR2B
    // Clear previous settings
    TCCR2A &= ~((1 << COM2B1) | (1 << COM2B0) | (1 << WGM21) | (1 << WGM20));
    TCCR2B &= ~(1 << CS22 | 1 << CS21 | 1 << CS20 | (1 << WGM22));
    // Set Fast PWM, non-inverting mode
    TCCR2A |= (1 << COM2B1) | (1 << WGM21) | (1 << WGM20); // Fast PWM 8-bit
    TCCR2B |= (1 << CS21);                                 // Prescaler = 8
    // Set duty cycle
    OCR2B = 255;
}

static void SetDutyCycle0A(uint8_t duty) {
    OCR0A = duty; 
}
static void SetDutyCycle0B(uint8_t duty) {
    OCR0B = duty;
}
static void SetDutyCycle1A(uint8_t duty) {
    OCR1A = duty;
}
static void SetDutyCycle1B(uint8_t duty) {
    OCR1B = duty;
}
static void SetDutyCycle2A(uint8_t duty) {
    OCR2A = duty;
}
static void SetDutyCycle2B(uint8_t duty) {
    OCR2B = duty;
}