#pragma once
#include "../lib/Pin.hpp"
#include <avr/io.h>


namespace pwm
{
    #if defined(__AVR_ATmega8__)
    #include "../include/timers/ATMega8_timers.hpp"
    #elif defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__)
    #include "../include/timers/ATMega168_timers.hpp"
    #endif

    template<int Timer, char Channel>
    struct PWMTraits;

    // TIMER0 A  (PD6)
    template<>
    struct PWMTraits<0, 'A'>
    {
        static inline void init(uint8_t d) { Timer0A(d); }
        static inline void set (uint8_t d) { SetDutyCycle0A(d); }
    };

    // TIMER0 B  (PD5)
    template<>
    struct PWMTraits<0, 'B'>
    {
        static inline void init(uint8_t d) { Timer0B(d); }
        static inline void set (uint8_t d) { SetDutyCycle0B(d); }
    };

    // TIMER1 A  (PB1)
    template<>
    struct PWMTraits<1, 'A'>
    {
        static inline void init(uint8_t d) { Timer1A(d); }
        static inline void set (uint8_t d) { SetDutyCycle1A(d); }
    };

    // TIMER1 B  (PB2)
    template<>
    struct PWMTraits<1, 'B'>
    {
        static inline void init(uint8_t d) { Timer1B(d); }
        static inline void set (uint8_t d) { SetDutyCycle1B(d); }
    };

    // TIMER2 A  (PB3)
    template<>
    struct PWMTraits<2, 'A'>
    {
        static inline void init(uint8_t d) { Timer2A(d); }
        static inline void set (uint8_t d) { SetDutyCycle2A(d); }
    };

    // TIMER2 B  (PD3)
    template<>
    struct PWMTraits<2, 'B'>
    {
        static inline void init(uint8_t d) { Timer2B(d); }
        static inline void set (uint8_t d) { SetDutyCycle2B(d); }
    };


    template<char PORT, uint8_t BIT>
    struct PWMSelect;

    template<>
    struct PWMSelect<'D', 6> { static constexpr int timer = 0; static constexpr char channel = 'A'; };

    template<>
    struct PWMSelect<'D', 5> { static constexpr int timer = 0; static constexpr char channel = 'B'; };

    template<>
    struct PWMSelect<'B', 1> { static constexpr int timer = 1; static constexpr char channel = 'A'; };

    template<>
    struct PWMSelect<'B', 2> { static constexpr int timer = 1; static constexpr char channel = 'B'; };
    
    template<>
    struct PWMSelect<'B', 3> { static constexpr int timer = 2; static constexpr char channel = 'A'; };
    
    template<>
    struct PWMSelect<'D', 3> { static constexpr int timer = 2; static constexpr char channel = 'B'; };


    template<char PORT, uint8_t BIT>
    class PWM
    {
    public:
        PWM() 
        { 
            pin::Pin<PORT, BIT>::SetOutput(); 
        }

        static inline void InitTimer()
        {
            constexpr int T  = PWMSelect<PORT, BIT>::timer;
            constexpr char C = PWMSelect<PORT, BIT>::channel;
            PWMTraits<T, C>::init(255);
        }

        static inline void SetDutyCycle(uint8_t duty)
        {
            constexpr int T  = PWMSelect<PORT, BIT>::timer;
            constexpr char C = PWMSelect<PORT, BIT>::channel;
            PWMTraits<T, C>::set(duty);
        }
    };

    using pd5 = PWM<'D', 5>;
    using pd6 = PWM<'D', 6>;
    using pb1 = PWM<'B', 1>;
    using pb2 = PWM<'B', 2>;
    using pb3 = PWM<'B', 3>;
    using pd3 = PWM<'D', 3>;
};