// #include "Counter.h"
// #include <util/delay.h>

// Counter::Counter() 
//     :
//     counter(0),
//     bright(0),
//     increment(true),
//     change(true),
//     btn1Pressed(false),
//     btn2Pressed(false),
//     speed(0.3f)
// {
//     fltBit.InitTimer();
//     bit1.SetAsOutput();
//     bit2.SetAsOutput();
//     btn1.SetAsInput();
//     btn2.SetAsInput();
// }

// void Counter::Count() {
//     if (increment) {
//         Increment(speed);
//     }
//     else {
//         Decrement(speed);
//     }
//     ShowOutput();
//     _delay_ms(1);
// }

// void Counter::Test() {
//     bit1.ToggleState();
// }

// void Counter::ShowOutput() {
//     fltBit.SetDutyCycle(bright);
//     if (change) {
//         change = false;
//         switch (counter) {
//         case 0:
//             bit1.SetState(false);
//             bit2.SetState(false);
//             break;
//         case 1:
//             bit1.SetState(true);
//             bit2.SetState(false);
//             break;
//         case 2:
//             bit1.SetState(false);
//             bit2.SetState(true);
//             break;
//         case 3:
//             bit1.SetState(true);
//             bit2.SetState(true);
//             break;     
//         }
//     }
// }

// // void Counter::Btn1Read()
// // {
// //     static uint16_t debounceCounter = 0;
// //     if (btn1.ReadState() && debounceCounter > DEBOUNCE_COUNT) {
// //         if (!btn1Pressed) {
// //             if (speed < maxSpeed) {
// //                 speed += 0.04f;
// //                 debounceCounter = 0;
// //             } 
// //             btn1Pressed = true;
// //         }
// //     }
// //     else {
// //         btn1Pressed = false;
// //         debounceCounter = 0;
// //     }
// // }

// void Counter::Btn2Read()
// {
//     static uint16_t debounceCounter = 0;
//     if (btn2.ReadState()) {
//         if (!btn2Pressed && debounceCounter > DEBOUNCE_COUNT) {
//             if (speed > minSpeed) {
//                 speed -= 0.04;
//             } 
//             btn2Pressed = true;
//         }
//     }
//     else {
//         btn2Pressed = false;
//     }
// }

// void Counter::Increment(float val) 
// {
//     if (bright < 30.0f) {
//         bright += val;
//     }
//     else if (bright >= 30.0f && bright < 100.0f) {
//         bright += (2*val);
//     }
//     else if (bright >= 100.0f && bright < 175.0f){
//         bright += (5*val);
//     }
//     else  {
//         bright += (9*val);
//     }
//     if (bright >= 250.0f) {
//         counter++;
//         if (counter > 3) {
//             counter = 3;
//             Reverse();
//         }
//         else {
//             bright = 0.0f;
//         }
//         change = true;
//         _delay_ms(20);
//     }
// }

// void Counter::Decrement(float val) {
//     if (bright < 30.0f) {
//         bright -= val;
//     }
//     else if (bright >= 30.0f && bright < 100.0f) {
//         bright -= (2*val);
//     }
//     else if (bright >= 100.0f && bright < 175.0f){
//         bright -= (5*val);
//     }
//     else  {
//         bright -= (9*val);
//     }
//     if (bright <= maxSpeed) {
//         counter--;
//         if (counter < 0) {
//             counter = 0;
//             Reverse();
//         }
//         else {
//             bright = 255.0f;
//         }
//         change = true;
//             _delay_ms(20);
//     }
// }

// void Counter::Reverse() {
//     increment = !increment;
// }

