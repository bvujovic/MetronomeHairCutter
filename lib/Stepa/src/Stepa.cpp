#include "Stepa.h"

Stepa::Stepa(int pinDir, int pinStep)
{
    this->pinDir = pinDir;
    this->pinStep = pinStep;
    pinMode(pinStep, OUTPUT);
    pinMode(pinDir, OUTPUT);
    setLowSpeed();
}

void Stepa::step(bool dir)
{
    setDir(dir);
    step();
}

void Stepa::step()
{
    digitalWrite(pinStep, true);
    delay(speedDelay);
    digitalWrite(pinStep, false);
    delay(speedDelay);
}