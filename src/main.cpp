#include <Arduino.h>

// const int STEPS_PER_REV = 200;
#include "Stepa.h"
Stepa stepa(2, 3);
const int AMPLITUDE = 100; // koliko koraka se rucica krece levo-desno
const int pinMicroStep = 4; // neki od MS(1,2,3) pinova sa A4988 se moze povezati na ovaj pin za mikro step

enum State
{
  Settings, // podesavanja pozicije i amplitude rucice
  Forward,  // kretanje rucice unapred (sporije)
  Pause1,   // pauza izmedju kretanja unapred i unazad
  Backward, // kretanje rucice unazad (brze)
  Pause2    // pauza izmedju kretanja unazad i unapred
};
State state = Settings;
int i = 0; //, s = 1;
unsigned int itvPause = 500;
long msPauseStart;

const int pinBtnFwd = A2;
const int pinBtnBck = A0;
long msStateChange; // promena stanja Settings -> radno stanje ili obratno

const int pinLed = LED_BUILTIN;

// Citanje stanja sa PULLUP tastera.
bool buttonRead(int pin) { return !digitalRead(pin); }

// ON/OFF ugradjene LED diode.
void ledOn(bool on) { digitalWrite(pinLed, on); }

void setup()
{
  pinMode(pinLed, OUTPUT);
  ledOn(false);

  pinMode(pinBtnFwd, INPUT_PULLUP);
  pinMode(pinBtnBck, INPUT_PULLUP);
  msStateChange = millis();

  pinMode(pinMicroStep, OUTPUT);
  digitalWrite(pinMicroStep, true);
}

void loop()
{
  if (state == Settings)
  {
    bool btnFwd = buttonRead(pinBtnFwd);
    bool btnBck = buttonRead(pinBtnBck);

    if (btnFwd && btnBck && millis() - msStateChange > 1000)
    {
      state = Backward;
      stepa.setDir(false);
      stepa.setHighSpeed();
      i = AMPLITUDE / 2; // rucka bi trebalo da je na sredini -> ide pola amplitude unazad do pocetne pozicije
      msStateChange = millis();
    }
    else if (btnFwd)
      stepa.step(true);
    else if (btnBck)
      stepa.step(false);
  }
  else // state nije Settings - moze biti bilo sta drugo
  {
    if (buttonRead(pinBtnFwd) && buttonRead(pinBtnBck) && millis() - msStateChange > 1000)
    {
      state = Settings;
      stepa.setLowSpeed();
      msStateChange = millis();
    }
  }

  if (state == Forward || state == Backward)
  {
    if (++i >= AMPLITUDE)
    {
      i = 0;
      stepa.invertDir();
      stepa.invertSpeed();
      state = state == Forward ? Pause1 : Pause2;
      msPauseStart = millis();
    }
    else
      stepa.step();
  }
  else if ((state == Pause1 || state == Pause2) && millis() - msPauseStart > itvPause)
    // ako je pauza istekla, prelazi se na kretnju
    state = state == Pause1 ? Backward : Forward;
}
