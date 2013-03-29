#include <Ethernet.h>

// In the first octet, the two least significant bits are significant:
//
// * The LSB specifies whether the MAC address is unicast (0) or multicast (1).
//   In our case, we want Unicast (0).
//
// * The second-least significant bit specifies whether the address is globally
//   unique (0) or locally administered (1). Since I don't have an OUI to
//   allocate addresses in, this should always be 1.
//
// So the two LSBs of the first octet of the MAC address should be 10, so the
// first octet should be a multiple of 0x03. Then we're free to choose what we
// like for the rest, so long as it doesn't collide with anything else on the
// local network.
byte macAddress[] = { 0x06, 0x01, 0x02, 0x03, 0x04, 0x05 };

const IPAddress localIp(192, 168, 2, 103);
const IPAddress gatewayIp(192, 168, 2, 1);
const IPAddress dnsIp(8, 8, 8, 8);

const IPAddress timeServer(12, 10, 191, 251); // time, nist, gov
const unsigned int timeServerPort = 13;

EthernetClient ethernetClient;

const unsigned int baudRate = 9600;

void setup()
{
  Serial.begin(baudRate);
  Ethernet.begin(macAddress, localIp, dnsIp, gatewayIp);
}

void loop()
{
  delay(5000);

  Serial.print("Connecting... ");
  if(ethernetClient.connect(timeServer, timeServerPort) <= 0) {
    Serial.println("Connection failed.");
  } else {
    Serial.println("Connected.");

    delay(300);

    while(ethernetClient.available()) {
      char c = ethernetClient.read();
      Serial.print(c);
    }
    Serial.println(' ');

    Serial.println("Disconnecting.");
    ethernetClient.stop();
  }
}
