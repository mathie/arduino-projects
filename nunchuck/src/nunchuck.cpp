// vim: set ft=arduino:

#include "nunchuck.h"

#include <Wire.h>

void Nunchuck::setup() {
  Wire.begin();
  handshake();
}

void Nunchuck::printUpdate() {
  update();

  for (unsigned int currentByte = 0; currentByte < 6; currentByte++) {
    Serial.print(_buffer[currentByte]);
    Serial.print(' ');
  }
  Serial.println('x');
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

