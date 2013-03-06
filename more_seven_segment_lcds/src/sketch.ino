#include "lcd_array.h"



const unsigned int digitPins[] = { 1, 2, 3, 4, NULL };
const unsigned int segmentPins[] = { 5, 6, 7, 8, 9, 10, 11 };
const unsigned int dpSegmentPin = 12;

LcdArray lcdArray(digitPins, segmentPins, dpSegmentPin);

void setup()
{
  randomSeed(analogRead(A0));
  const unsigned int randomNumber = random(1, 2000);

  lcdArray.changeNumber(randomNumber, 0);
}

void loop()
{
  lcdArray.refreshNumber();
}
