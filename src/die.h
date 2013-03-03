#ifndef DIE_H
#define DIE_H

#include "lcd_digit.h"
#include "button.h"

class Die {
  public:
  Die(
    const LcdDigit lcdDigit, Button button,
    const unsigned int numberOfSides,
    const unsigned int maximumTries      = 50,
    const unsigned int delayBetweenTries = 50
  );

  void run();

  private:

  const bool isButtonPressed();
  void rollRandomNumber();
  void displayNumber(const unsigned int number);
  const unsigned int tries();
  const unsigned int randomNumber();

  const LcdDigit _lcdDigit;
  Button _button;
  const unsigned int _numberOfSides, _maximumTries, _delayBetweenTries;
};

#endif
