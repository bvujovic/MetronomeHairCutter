#pragma once

#include <Arduino.h>

class Stepa
{
private:
    int pinDir;                // direction pin za A4988
    int pinStep;               // step pin za A4988
    bool dir = true;           // smer rotacije motora: true -> napred, false -> nazad
    int speedDelay = 1;        // vreme trajanja jednog koraka u ms - veci broj manja brzina motora
    const int SLOW = 20;       // mala brzina motora - shishanje
    const int FAST = 10;       // veca brzina motora - vracanje rucice u pocetni polozaj

public:
    Stepa(int pinDir, int pinStep);

    bool getDir() { return dir; }
    void setDir(bool isFwd) { digitalWrite(pinDir, dir = isFwd); }
    void invertDir() { setDir(!dir); }

    void setLowSpeed() { speedDelay = SLOW; }
    void setHighSpeed() { speedDelay = FAST; }
    void invertSpeed() { speedDelay = speedDelay == FAST ? SLOW : FAST; }

    void step(bool dir);
    void step();
};
