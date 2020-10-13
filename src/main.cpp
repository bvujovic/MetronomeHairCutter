#include <Arduino.h>

#include <Stepper.h>
#define STEPS 200
Stepper stepper(STEPS, 8, 9, 10, 11);

void setup()
{
  stepper.setSpeed(10);
}

void loop()
{
  stepper.step(-1);
}