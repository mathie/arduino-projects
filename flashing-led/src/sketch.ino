const byte ledPin = 13;
const unsigned int period = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  static unsigned long millisAtStateChange = 0;
  static unsigned int currentState = LOW;

  unsigned long currentMillis = millis();
  if (currentMillis >= (millisAtStateChange + period)) {
    millisAtStateChange = currentMillis;
    if(currentState == HIGH) {
      currentState = LOW;
    } else {
      currentState = HIGH;
    }
    digitalWrite(ledPin, currentState);
  }
}
