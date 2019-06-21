/*
  hazardLight.cpp - Based on Andrew Lombardo's library (http://www.lombardoandrea.com  )
  Author:   Daniel Knox
*/

#include "hazardLight.h"

typedef void (*CallBackFunction) ();

Hazardlight::Hazardlight(uint8_t pinIN1, uint8_t pinIN2){
  _pinIN1 = pinIN1;
  _pinIN2 = pinIN2;
  _isOn = false;
  _canFlash = true;
  _isFlashing = false;
  _startMs = 0;
  _lastMs = 0;
  pinMode(_pinIN1, OUTPUT);
  pinMode(_pinIN2, OUTPUT);
}

void Hazardlight::on(){
  digitalWrite(_pinIN1, HIGH);
  digitalWrite(_pinIN2, LOW);
  _isOn = true;
}

void Hazardlight::off(){
  digitalWrite(_pinIN1, LOW);
  digitalWrite(_pinIN2, LOW);  
  _isOn = false;
}

void Hazardlight::startFlashing(unsigned long rate){
  if ((_lastMs == 0) && _canFlash) {
    this->on();
    _isFlashing = true;
  }
  if( ((millis() - _lastMs) >= rate) && _canFlash){
    _isOn ? this->off() : this->on();
    _lastMs = millis();
  } 
}

void Hazardlight::stopFlashing(){
  this->off();
  _isFlashing = false;
  _lastMs = 0;
  _canFlash = false;
  _startMs = 0;
}

void Hazardlight::flashFor(unsigned long delay, unsigned long rate, CallBackFunction callback){
  // We use millis so this method can be repeatedly called. This allows for 'fake' non-blocking multitasking.
  if ((_startMs == 0) && _canFlash) {
    _startMs = millis();
    this->on();
    _isFlashing = true;
  } else if (((millis() - _startMs) < delay) && _canFlash) {
    if( (millis() - _lastMs) >= rate){
      _isOn ? this->off() : this->on();
      _lastMs = millis();
    }
  }

  if (((millis() - _startMs) > delay) && _canFlash) {
    this->off();
    _startMs = 0;
    _lastMs = 0;
    _canFlash = false;
    _isFlashing = false;
    callback();
  }

}

void Hazardlight::flashFor(unsigned long delay,unsigned long rate){
  this->flashFor(delay, rate, fakeCallback);
}

void Hazardlight::reset(){
  _canFlash = true;
}

boolean Hazardlight::isOn(){
  return _isOn;
}

boolean Hazardlight::isFlashing(){
  return _isFlashing;
}

void Hazardlight::fakeCallback(){

}