// vim: set ft=arduino:

#include "time_display.h"
#include "lcd_array.h"

#include <Arduino.h>

TimeDisplay::TimeDisplay(LcdArray *lcdArray)
  : _lcdArray(lcdArray)
{
  _previousTime = micros();
  _lcdArray->changeNumber(0, 1);
}

void TimeDisplay::refresh() {
  const unsigned long currentTime = micros();
  if (currentTime >= (_previousTime + _oneSecond)) {
    _previousTime = currentTime;

    const unsigned long currentTimeInSeconds = currentTime / _oneSecond;
    const unsigned long seconds = currentTimeInSeconds % 60;
    const unsigned long minutes = currentTimeInSeconds / 60;
    const unsigned long representation = (minutes * 100) + seconds;
    _lcdArray->changeNumber(representation, 1);
  }

  _lcdArray->refreshNumber();
}

