#include <Wire.h>

class Nunchuck {
  public:

  void setup();
  void printUpdate();

  private:
  void handshake();
  bool update();

  void sendHandshakeCommand();
  void sendUpdateCommand();
  bool  getResponse();

  static const byte _nunchuckDeviceId = 0x52;
  static const byte _handshakeCommand = 0x40;
  static const byte _getUpdateCommand = 0x00;
  static const unsigned int _packetSize = 6;
  byte _buffer[_packetSize];
};

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
