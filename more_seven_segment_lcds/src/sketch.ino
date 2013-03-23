#include "time_display.h"
#include "lcd_array.h"
#include "button.h"

const unsigned int digitPins[]   = { 1, 2, 3, 4, NULL };
const unsigned int segmentPins[] = { 5, 6, 7, 8, 9, 10, 11 };
const unsigned int dpSegmentPin = 12;

const unsigned int resetButtonPin = 0;
const unsigned int startStopButtonPin = 13;

LcdArray lcdArray(digitPins, segmentPins, dpSegmentPin);
TimeDisplay timeDisplay(&lcdArray);
Button resetButton(resetButtonPin), startStopButton(startStopButtonPin);

void setup() {
}

void loop()
{
  if(resetButton.isUpdated() && resetButton.isPressed()) {
    timeDisplay.reset();
  }

  if(startStopButton.isUpdated() && startStopButton.isPressed()) {
    timeDisplay.toggle();
  }

  timeDisplay.refresh();
}
