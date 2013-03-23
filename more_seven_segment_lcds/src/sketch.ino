#include "time_display.h"
#include "lcd_array.h"
#include "button.h"

const unsigned int digitPins[]   = { 1, 2, 3, 4, NULL };
const unsigned int segmentPins[] = { 5, 6, 7, 8, 9, 10, 11 };
const unsigned int dpSegmentPin = 12;

const unsigned int buttonPin = 13;

LcdArray lcdArray(digitPins, segmentPins, dpSegmentPin);
TimeDisplay timeDisplay(&lcdArray);
Button button(buttonPin);

const unsigned long seconds = 1000000;
unsigned long buttonPressedAt;
bool actionPerformed;

void setup() {
  buttonPressedAt = 0;
  actionPerformed = true;
}

void loop()
{
  if (button.isUpdated()) {
    if (button.isPressed()) {
      actionPerformed = false;
      buttonPressedAt = micros();
    } else {
      buttonPressedAt = 0;
      if (!actionPerformed) {
        actionPerformed = true;
        timeDisplay.toggle();
      }
    }
  }

  if (!actionPerformed && (buttonPressedAt + 2 * seconds <= micros())) {
    timeDisplay.reset();
    actionPerformed = true;
  }

  timeDisplay.refresh();
}
