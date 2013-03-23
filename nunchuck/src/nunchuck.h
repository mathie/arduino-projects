// vim: set ft=arduino:

#ifndef NUNCHUCK_H
#define NUNCHUCK_H

#include <Arduino.h>

class Nunchuck {
  public:
  void setup();
  bool update();

  const unsigned int getJoystickX() const;
  const unsigned int getJoystickY() const;
  const unsigned int getXAcceleration() const;
  const unsigned int getYAcceleration() const;
  const unsigned int getZAcceleration() const;
  const bool getCButton() const;
  const bool getZButton() const;

  private:
  void handshake();

  void sendHandshakeCommand();
  void sendUpdateCommand();
  bool getResponse();

  static const byte _nunchuckDeviceId = 0x52;
  static const byte _handshakeCommand = 0x40;
  static const byte _getUpdateCommand = 0x00;
  static const unsigned int _packetSize = 6;
  byte _buffer[_packetSize];
};

#endif
