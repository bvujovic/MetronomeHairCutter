// #include <Arduino.h>

// // #include <Stepper.h>
// // #define STEPS 200
// // Stepper stepper(STEPS, 8, 9, 10, 11);

// #include <AccelStepper.h>
// //B AccelStepper stepper2(AccelStepper::FULL4WIRE, 6, 7, 8, 9);
// AccelStepper stepper(AccelStepper::FULL4WIRE, 8, 9, 10, 11);

// int s = 1;
// const int pinBtn = 4;

// void setup()
// {
//   pinMode(pinBtn, INPUT_PULLUP);
//   // stepper.setSpeed(20);

//   stepper.setMaxSpeed(100);
//   stepper.setAcceleration(20);
//   stepper.moveTo(200);
// }

// void loop()
// {
//   // s = digitalRead(pinBtn) ? 1 : -1;
//   // stepper.step(s);

//     if (stepper.distanceToGo() == 0)
//       stepper.moveTo(-stepper.currentPosition());

//     stepper.run();
// }