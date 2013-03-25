// vim: set ft=arduino:

#ifndef NUNCHUCK_H
#define NUNCHUCK_H

#include <Arduino.h>

class NunchuckStatus;

class Nunchuck {
  public:
  void setup();
  NunchuckStatus *getStatus();

  private:
  void handshake();
  bool update();

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
