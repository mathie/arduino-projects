#include "time_display.h"
#include "lcd_array.h"

const unsigned int digitPins[]   = { 1, 2, 3, 4, NULL };
const unsigned int segmentPins[] = { 5, 6, 7, 8, 9, 10, 11 };
const unsigned int dpSegmentPin = 12;

LcdArray lcdArray(digitPins, segmentPins, dpSegmentPin);
TimeDisplay timeDisplay(&lcdArray);

void setup() { }

void loop()
{
  timeDisplay.refresh();
}
