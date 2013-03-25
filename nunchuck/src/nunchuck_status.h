// vim: set ft=arduino:

#ifndef NUNCHUCK_STATUS_H
#define NUNCHUCK_STATUS_H

#include <Arduino.h>

class NunchuckStatus {
  public:
  NunchuckStatus(const byte *packet);

  const unsigned int getJoystickX() const;
  const unsigned int getJoystickY() const;
  const unsigned int getXAcceleration() const;
  const unsigned int getYAcceleration() const;
  const unsigned int getZAcceleration() const;
  const bool getCButton() const;
  const bool getZButton() const;

  private:

  unsigned int _joystickX, _joystickY;
  unsigned int _accelerationX, _accelerationY, _accelerationZ;
  bool _buttonC, _buttonZ;
};

#endif
