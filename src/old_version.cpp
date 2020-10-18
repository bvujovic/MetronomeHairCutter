// //* Opis projekta: Aparat stoji pricvrscen za neku podlogu (sto npr.) i svojim motorima pomera drsku sa
// //* trimerom u stilu metronoma. Na taj nacin bi se mogla shishati ledja ili neki teze dostupan deo tela.
// //* Napajanje:  18650 baterija ili 5V sa transformatora (ako aparat trosi manje od 0.5-0.6A)
// //* Senzori:    /
// //* Aktuatori:  steper i servo motor (mozda samo steper)
// //* Aparat moze da stoji na komodi u predsoblju kada se koristi
// //* Za podlogu moze da se pricvrsti uz pomoc mehanizma slicnog stegi ili uz pomoc gumenih/silikonskih prilepaka
// //* Poboljsanja:

// #include <Arduino.h>
// #include <Stepper.h>
// // Alternativna biblioteka za rad sa steperom: http://www.airspayce.com/mikem/arduino/AccelStepper/

// const int STEPS = 100; //the steps of a circle
// Stepper stepper(STEPS, 2, 4, 3, 5);

// enum State
// {
//   Settings, // podesavanja pozicije i amplitude rucice
//   Forward,  // kretanje rucice unapred (sporije)
//   Pause1,   // pauza izmedju kretanja unapred i unazad
//   Backward, // kretanje rucice unazad (brze)
//   Pause2    // pauza izmedju kretanja unazad i unapred
// };
// State state = Settings;
// int i = 0, s = 1;
// int itvPause = 500;
// long msPauseStart;

// const int pinBtnFwd = A5;
// const int pinBtnBck = A3;
// long ms;
// long msStateChange;        // promena stanja Settings -> radno stanje ili obratno
// int step = 1;              // korak (smer) motora
// int speed = 50;            // brzina motora
// const int AMPLITUDE = 300; // koliko koraka se rucica krece levo-desno
// const int SLOW = 66;       // mala brzina motora - shishanje
// const int FAST = 132;      // veca brzina motora - vracanje rucice u pocetni polozaj

// void setup()
// {
//   Serial.begin(9600);
//   Serial.println("Start");
//   stepper.setSpeed(SLOW);
//   pinMode(pinBtnFwd, INPUT);
//   pinMode(pinBtnBck, INPUT);
//   msStateChange = millis();
// }

// void SetStepper(int v, int minV = 0)
// {
//   const int MAX_SPEED = 250;
//   step = v >= 0 ? 1 : -1;
//   if (v >= -minV && v <= minV)
//     step = 0;
//   else
//   {
//     v = v >= 0 ? v : -v;
//     speed = v > MAX_SPEED ? MAX_SPEED : v;
//   }
// }

// void loop()
// {
//   if (state == Settings)
//   {
//     bool btnFwd = digitalRead(pinBtnFwd);
//     bool btnBck = digitalRead(pinBtnBck);
//     if (btnFwd && btnBck && millis() - msStateChange > 1000)
//     {
//       state = Backward;
//       s = 1;
//       stepper.setSpeed(FAST);
//       i = AMPLITUDE / 2; // rucka bi trebalo da je na sredini -> ide pola amplitude unazad do pocetne pozicije
//       msStateChange = millis();
//     }
//     else if (btnFwd)
//       stepper.step(1);
//     else if (btnBck)
//       stepper.step(-1);
//   }
//   else // state nije Settings - moze biti bilo sta drugo
//   {
//     if (digitalRead(pinBtnFwd) && digitalRead(pinBtnBck) && millis() - msStateChange > 1000)
//     {
//       state = Settings;
//       stepper.setSpeed(SLOW);
//       msStateChange = millis();
//     }
//   }

//   if (state == Forward || state == Backward)
//   {
//     if (++i >= AMPLITUDE)
//     {
//       i = 0;
//       s = -s;
//       stepper.setSpeed(s > 0 ? FAST : SLOW);
//       //T Serial.println(state);
//       //T Serial.println(s);
//       state = state == Forward ? Pause1 : Pause2;
//       msPauseStart = millis();
//     }
//     else
//       stepper.step(s);
//   }
//   else if ((state == Pause1 || state == Pause2) && millis() - msPauseStart > itvPause)
//     // ako je pauza istekla, prelazi se na kretnju
//     state = state == Pause1 ? Backward : Forward;
// }
