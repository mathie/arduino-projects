#include <Arduino.h>
#include "button.h"

Button::Button(const unsigned int inputPin) : _inputPin(inputPin) {
  pinMode(inputPin, INPUT);
  _previousState = readValue();
}

const bool Button::isUpdated() {
  _currentState = readValue();
  const bool updated = (_currentState != _previousState);
  _previousState = _currentState;
  return updated;
}

const bool Button::isPressed() const {
  return _currentState == HIGH;
}

const unsigned int Button::readValue() const {
  return digitalRead(_inputPin);
}
