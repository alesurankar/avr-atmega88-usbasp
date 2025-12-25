#pragma once
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>


class UART 
{
public:
    void Init(void) {
        UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
        UBRR0L = (uint8_t)UBRR_VALUE;

        UCSR0B = (1 << TXEN0);                 // Enable transmitter
        UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 data bits, 1 stop bit
    }
    void Send(char c) {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = c;
    }
    void SendString(const char *s) {
        while (*s) {
            Send(*s++);
        }
    }
    void SendUint(uint32_t num) {
        char buf[12];
        ultoa(num, buf, 10);
        SendString(buf);
    }
    void NewLine()
    {
        SendString("\r\n");
    }
    void Clear()
    {
        SendString("\033[2J\033[H");
    }
private:
    static constexpr uint32_t BAUD = 9600;
    static constexpr uint32_t UBRR_VALUE = ((F_CPU / (16UL * BAUD)) - 1);
};