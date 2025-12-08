// #include "../lib/Pin.hpp"
// #include "../lib/PWM.hpp"

// class Counter
// {
// public:
//     Counter();
//     void Count();
//     void Test();
//     void ShowOutput();
//     void Btn1Read();
//     void Btn2Read();
// private:
//     void Increment(float val);
//     void Decrement(float val);
//     void Reverse();
// private:
//     pwm::pd5 fltBit;
//     pin::pd6 bit1;
//     pin::pd7 bit2;
//     int counter = 0;
//     float bright = 0.0f;
//     bool increment = true;
//     bool change = true;
//     pin::pc4 btn1;
//     pin::pc5 btn2;
//     bool btn1Pressed = false;
//     bool btn2Pressed = false;
//     float speed = 0.3f;
//     static constexpr float maxSpeed = 2.0f;
//     static constexpr float minSpeed = 0.05f;
//     static constexpr uint16_t DEBOUNCE_COUNT = 20;
// };