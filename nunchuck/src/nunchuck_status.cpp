// vim: set ft=arduino:

#include "nunchuck_status.h"

NunchuckStatus::NunchuckStatus(const byte *buffer) {
  _joystickX = buffer[0];
  _joystickY = buffer[1];

  _accelerationX = (buffer[2] << 2) | ((buffer[5] >> 2) & 0x03);
  _accelerationY = (buffer[3] << 2) | ((buffer[5] >> 4) & 0x03);
  _accelerationZ = (buffer[4] << 2) | ((buffer[5] >> 6) & 0x03);

  _buttonC = !(buffer[5] & 0x01);
  _buttonZ = !(buffer[5] & 0x02);
}

const unsigned int NunchuckStatus::getJoystickX() const {
  return _joystickX;
}

const unsigned int NunchuckStatus::getJoystickY() const {
  return _joystickY;
}

const unsigned int NunchuckStatus::getXAcceleration() const {
  return _accelerationX;
}

const unsigned int NunchuckStatus::getYAcceleration() const {
  return _accelerationY;
}

const unsigned int NunchuckStatus::getZAcceleration() const {
  return _accelerationZ;
}

const bool NunchuckStatus::getCButton() const {
  return _buttonC;
}

const bool NunchuckStatus::getZButton() const {
  return _buttonZ;
}
