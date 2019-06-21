#include <hazardLight.h>

//pin definition
#define IN1 4
#define IN2 5

//create a hazardlight instance
Hazardlight hazardlight(IN1, IN2);

void setup() {

  //used for display information
  Serial.begin(9600);
}

void loop() {

  //tell the hazard light to turn on (may depend by your wiring)
  hazardlight.on();

  //print the hazard light satus in the serial monitor
  Serial.print("Is on = ");
  Serial.println(hazardlight.isOn());

  delay(3000);

  //turn off hazard light
  hazardlight.off();

  Serial.print("Is on = ");
  Serial.println(hazardlight.isOn());

  delay(3000);

  //tell the hazard light to flash for a period of time (may depend by your wiring)
  hazardlight.reset();
  do {
   hazardlight.flashFor(5000,500);
  } while( hazardlight.isFlashing() );
  delay(3000);

  //tell the hazard light to continously flash (may depend by your wiring) until a statement is no longer true
  unsigned long _startMs = millis();
  hazardlight.reset();
  do {
   hazardlight.startFlashing(500);
  } while( (millis() - _startMs) < 5000 );
  hazardlight.stopFlashing();
  delay(3000);

}
