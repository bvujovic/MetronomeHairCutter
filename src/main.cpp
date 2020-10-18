#include <Arduino.h>

const int pinDir = 2;
const int pinStep = 3;
const int STEPS_PER_REV = 200;

#include <ClickButton.h>
ClickButton btn(A0, LOW, CLICKBTN_PULLUP);

const int pinLed = LED_BUILTIN;
bool isLedOn = false;
const int pinBtn = A0;
bool dir = true;

void setup()
{
  pinMode(pinStep, OUTPUT);
  pinMode(pinDir, OUTPUT);
  digitalWrite(pinDir, dir);

  btn.multiclickTime = 100; // originalno 500

  pinMode(pinLed, OUTPUT);
  pinMode(pinBtn, INPUT_PULLUP);
}

void step(int itv)
{
  digitalWrite(pinStep, true);
  // delayMicroseconds(itv);
  delay(itv);
  digitalWrite(pinStep, false);
  // delayMicroseconds(itv);
  delay(itv);
}

void loop()
{
  step(10);

  btn.Update();
  if (btn.clicks == 1)
  {
    digitalWrite(pinDir, dir = !dir);
    digitalWrite(pinLed, isLedOn = !isLedOn);
  }
}
