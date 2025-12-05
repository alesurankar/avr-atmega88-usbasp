#pragma once
#include "../lib/PWM.hpp"

class Dimming
{
public:
    enum class TYPE {
        INCR,
        DECR
    };
    Dimming();
    void SetType(TYPE type);
    void SetTime(int time);
    void Update();
private:
    void Prog1();
    void Prog2();
private:
    pwm::pd5 led;
    TYPE type;
    int time = 0; 
    float pwmCounter = 0.0f;
};