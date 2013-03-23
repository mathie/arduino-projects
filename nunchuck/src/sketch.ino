#include "nunchuck.h"

Nunchuck nunchuck;

void setup()
{
  Serial.begin(9600);
  nunchuck.setup();
}

void loop()
{
  nunchuck.update();

  Serial.print("joystick = ");
  Serial.print(nunchuck.getJoystickX());
  Serial.print(',');
  Serial.println(nunchuck.getJoystickY());

  Serial.print("Acceleration = ");
  Serial.print(nunchuck.getXAcceleration());
  Serial.print(',');
  Serial.print(nunchuck.getYAcceleration());
  Serial.print(',');
  Serial.println(nunchuck.getZAcceleration());

  Serial.print("button c = ");
  Serial.println(nunchuck.getCButton());
  Serial.print("button z = ");
  Serial.println(nunchuck.getZButton());

  delay(1000);
}
