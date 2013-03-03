#include <Arduino.h>
#include "die.h"

Die::Die(
  LcdDigit lcdDigit, Button button,
  const unsigned int numberOfSides,
  const unsigned int maximumTries,
  const unsigned int delayBetweenTries
) : _lcdDigit(lcdDigit), _button(button), _numberOfSides(numberOfSides),
    _maximumTries(maximumTries), _delayBetweenTries(delayBetweenTries) {
  randomSeed(analogRead(A0));
}

void Die::run() {
  if(isButtonPressed()) {
    rollRandomNumber();
  }
}

const bool Die::isButtonPressed() {
  return _button.isUpdated() && _button.isPressed();
}

void Die::rollRandomNumber() {
  for(unsigned int i = 0; i < tries(); i++) {
    displayNumber(randomNumber());
    delay(_delayBetweenTries);
  }
}

const unsigned int Die::tries() {
  return random(20, _maximumTries + 1);
}

const unsigned int Die::randomNumber() {
  return random(1, _numberOfSides + 1);
}

void Die::displayNumber(const unsigned int number) {
  _lcdDigit.displayNumber(number);
}
