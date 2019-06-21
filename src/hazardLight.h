#ifndef hazardLight_h
#define hazardLight_h

#include "Arduino.h"


typedef void (*CallBackFunction) ();

class Hazardlight{
   public:
      Hazardlight(uint8_t pinIN1, uint8_t pinIN2);
      void on();
      void off();
      void reset();
      boolean isOn();
      boolean isFlashing();
      void startFlashing(unsigned long rate);
      void stopFlashing();
      void flashFor(unsigned long delay, unsigned long rate, CallBackFunction callback);
      void flashFor(unsigned long delay, unsigned long rate);

   private:
      byte _pinIN1;
      byte _pinIN2;
      unsigned long _startMs;
      unsigned long _lastMs;
      boolean _canFlash;
      boolean _isFlashing;
      boolean _isOn;
      static void fakeCallback();
};

#endif