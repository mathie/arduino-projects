#include "lcd_array.h"

const unsigned hourDigitPins[] = { 1, 2, NULL };
const unsigned minuteDigitPins[] = { 3, 4, NULL };

const unsigned int segmentPins[] = { 5, 6, 7, 8, 9, 10, 11 };
const unsigned int dpSegmentPin = 12;

LcdArray hourLcdArray(hourDigitPins, segmentPins, dpSegmentPin);
LcdArray minuteLcdArray(minuteDigitPins, segmentPins, dpSegmentPin);

void setup()
{
  randomSeed(analogRead(A0));
  const unsigned int randomHour = random(0, 24);
  const unsigned int randomMinute = random(0, 60);

  hourLcdArray.changeNumber(randomHour);
  minuteLcdArray.changeNumber(randomMinute);
}

void loop()
{
  hourLcdArray.refreshNumber();
  minuteLcdArray.refreshNumber();
}
