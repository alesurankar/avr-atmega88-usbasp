#pragma once
#include <avr/io.h>
#include <stdlib.h>

class UART 
{
public:
    void uart_init(void) {
        UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
        UBRR0L = (uint8_t)UBRR_VALUE;

        UCSR0B = (1 << TXEN0);                 // Enable transmitter
        UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 data bits, 1 stop bit
    }
    void send(char c) {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = c;
    }
    void send_string(const char *s) {
        while (*s) {
            send(*s++);
        }
    }
    void send_int(int num) {
        char buf[10];
        itoa(num, buf, 10);
        send_string(buf);
    }
    void new_line()
    {
        send('\n');
        send('\r');
    }
private:
    static constexpr uint32_t BAUD = 9600;
    static constexpr uint32_t UBRR_VALUE = ((F_CPU / (16UL * BAUD)) - 1);
};