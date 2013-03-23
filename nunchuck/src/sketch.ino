#include "nunchuck.h"

Nunchuck nunchuck;

void setup()
{
  Serial.begin(9600);
  nunchuck.setup();
}

void loop()
{
  nunchuck.printUpdate();
  delay(1000);
}
