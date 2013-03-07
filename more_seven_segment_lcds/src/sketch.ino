#include "lcd_array.h"

const unsigned int digitPins[]   = { 1, 2, 3, 4, NULL };
const unsigned int segmentPins[] = { 5, 6, 7, 8, 9, 10, 11 };
const unsigned int dpSegmentPin = 12;

const unsigned int lDigitPin = 0;
const unsigned int lSegmentPins[] = { 5, 6, 7, NULL };

LcdArray lcdArray(digitPins, segmentPins, dpSegmentPin, lDigitPin, lSegmentPins);

void setup()
{
  randomSeed(analogRead(A0));
  const unsigned int randomNumber = 8888;
  const bool ls[] = { true, true, true };

  lcdArray.changeNumber(randomNumber, ls);
}

void loop()
{
  lcdArray.refreshNumber();
}
