// vim: set ft=arduino:

#include "time_display.h"
#include "lcd_array.h"

#include <Arduino.h>

TimeDisplay::TimeDisplay(LcdArray *lcdArray)
  : _lcdArray(lcdArray)
{
  _previousTime = micros();
  _currentTimeInSeconds = 0;

  changeNumber();
}

void TimeDisplay::refresh() {
  if(shouldTick()) {
    _currentTimeInSeconds++;
    changeNumber();
  }

  _lcdArray->refreshNumber();
}

bool TimeDisplay::shouldTick() {
  const unsigned long currentTime = micros();
  if (currentTime >= (_previousTime + _oneSecond) || (currentTime < _previousTime)) {
    _previousTime = currentTime;
    return true;
  }
  return false;
}

void TimeDisplay::changeNumber() {
  _lcdArray->changeNumber(representation(), 1);
}

const unsigned long TimeDisplay::representation() {
  return currentMinutes() * 100 + currentSeconds();
}

const unsigned long TimeDisplay::currentMinutes() {
  return _currentTimeInSeconds / 60;
}

const unsigned long TimeDisplay::currentSeconds() {
  return _currentTimeInSeconds % 60;
}
