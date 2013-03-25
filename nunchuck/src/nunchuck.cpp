// vim: set ft=arduino:

#include "nunchuck.h"
#include "nunchuck_status.h"

#include <Wire.h>

void Nunchuck::setup() {
  Wire.begin();
  handshake();
}

void Nunchuck::handshake() {
  sendHandshakeCommand();
  delay(1);
  getResponse();
}

NunchuckStatus *Nunchuck::getStatus() {
  if (update()) {
    return new NunchuckStatus(_buffer);
  } else {
    return NULL;
  }
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

