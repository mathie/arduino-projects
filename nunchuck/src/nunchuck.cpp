// vim: set ft=arduino:

#include "nunchuck.h"

#include <Wire.h>

void Nunchuck::setup() {
  Wire.begin();
  handshake();
}

const unsigned int Nunchuck::getJoystickX() const {
  return _buffer[0];
}

const unsigned int Nunchuck::getJoystickY() const {
  return _buffer[1];
}

const unsigned int Nunchuck::getXAcceleration() const {
  return (_buffer[2] << 2) | ((_buffer[5] >> 2) & 0x03);
}

const unsigned int Nunchuck::getYAcceleration() const {
  return (_buffer[3] << 2) | ((_buffer[5] >> 4) & 0x03);
}

const unsigned int Nunchuck::getZAcceleration() const {
  return (_buffer[4] << 2) | ((_buffer[5] >> 6) & 0x03);
}

const bool Nunchuck::getCButton() const {
  return !(_buffer[5] & 0x01);
}

const bool Nunchuck::getZButton() const {
  return !(_buffer[5] & 0x02);
}

void Nunchuck::handshake() {
  sendHandshakeCommand();
  delay(1);
  getResponse();
}

bool Nunchuck::update() {
  sendUpdateCommand();
  delay(1);
  return getResponse();
}

void Nunchuck::sendHandshakeCommand() {
  Wire.beginTransmission(_nunchuckDeviceId);
  Wire.write(_handshakeCommand);
  Wire.write(_getUpdateCommand);
  Wire.endTransmission();
}

void Nunchuck::sendUpdateCommand() {
  Wire.beginTransmission(_nunchuckDeviceId);
  Wire.write(_getUpdateCommand);
  Wire.endTransmission();
}

bool Nunchuck::getResponse() {
  Wire.requestFrom(_nunchuckDeviceId, _packetSize);
  unsigned int currentByte;
  for(currentByte = 0; currentByte < _packetSize && Wire.available(); currentByte++) {
    _buffer[currentByte] = (Wire.read() ^ 0x17) + 0x17;
  }
  return currentByte == _packetSize;
}

