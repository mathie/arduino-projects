#include "lcd_array.h"



const unsigned int digitPins[] = { 1, 2, 3, 4, NULL };
const unsigned int segmentPins[] = { 5, 6, 7, 8, 9, 10, 11 };
const unsigned int dpSegmentPin = 12;

LcdArray lcdArray(digitPins, segmentPins, dpSegmentPin);

unsigned int randomNumber;

void setup()
{
  randomSeed(analogRead(A0));
  randomNumber = random(1, 2000);
}

void loop()
{
  lcdArray.displayNumber(randomNumber, 0);
}
