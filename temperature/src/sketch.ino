const unsigned int ledPin = 13;
const unsigned int period = 1000;
const unsigned int temperaturePin = A0;
float aRefVoltage;

// This code is specific to the Mega2560 and is culled from the comments on
// https://code.google.com/p/tinkerit/wiki/SecretVoltmeter which leads with an
// equivalent for the Arduino 168 or 328. It returns a plausible looking value.
const float readVcc() {
  long result;
  ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  ADCSRB &= ~_BV(MUX5);
  delay(3); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH << 8;
  result = 1100000L / result; // Back-calculate AVcc in mV
  return result / 1000.0;
}

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  aRefVoltage = readVcc();
}

void flashLed() {
  static unsigned int currentState = LOW;

  if(currentState == HIGH) {
    currentState = LOW;
  } else {
    currentState = HIGH;
  }
  digitalWrite(ledPin, currentState);
}

void readTemperature() {
  int reading = analogRead(temperaturePin);

  float milliVolts = (reading * aRefVoltage) / 1024.0;

  Serial.print(milliVolts); Serial.println(" volts");

  float temperature = (milliVolts - 0.5) * 100;

  Serial.print(temperature); Serial.println(" degrees celsius");
}

void loop() {
  static unsigned long millisAtStateChange = 0;

  unsigned long currentMillis = millis();
  if (currentMillis >= (millisAtStateChange + period)) {
    millisAtStateChange = currentMillis;
    flashLed();
    readTemperature();
  }
}
