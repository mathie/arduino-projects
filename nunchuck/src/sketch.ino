#include "nunchuck.h"
#include "nunchuck_status.h"

Nunchuck nunchuck;

void setup()
{
  Serial.begin(9600);
  nunchuck.setup();
}

void loop()
{
  NunchuckStatus *status = nunchuck.getStatus();

  Serial.print("joystick = ");
  Serial.print(status->getJoystickX());
  Serial.print(',');
  Serial.println(status->getJoystickY());

  Serial.print("Acceleration = ");
  Serial.print(status->getXAcceleration());
  Serial.print(',');
  Serial.print(status->getYAcceleration());
  Serial.print(',');
  Serial.println(status->getZAcceleration());

  Serial.print("button c = ");
  Serial.println(status->getCButton());
  Serial.print("button z = ");
  Serial.println(status->getZButton());

  delete status;

  delay(1000);
}
