// vim: set ft=arduino:

#include "time_display.h"
#include "lcd_array.h"

#include <Arduino.h>

TimeDisplay::TimeDisplay(LcdArray *lcdArray)
  : _lcdArray(lcdArray)
{
  _previousTime = micros();
  reset();
}

void TimeDisplay::toggle() {
  if (_isRunning) {
    stop();
  } else {
    start();
  }
}

void TimeDisplay::stop() {
  _isRunning = false;
}

void TimeDisplay::start() {
  _isRunning = true;
  _previousTime = micros();
}

void TimeDisplay::reset() {
  _currentTimeInSeconds = 0;
  changeNumber();
  stop();
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
  if (_isRunning && (currentTime >= (_previousTime + _oneSecond) || (currentTime < _previousTime))) {
    _previousTime = currentTime;
    return true;
  }
  return false;
}

void TimeDisplay::changeNumber() const {
  _lcdArray->changeNumber(representation(), 1);
}

const unsigned long TimeDisplay::representation() const {
  return currentMinutes() * 100 + currentSeconds();
}

const unsigned long TimeDisplay::currentMinutes() const {
  return _currentTimeInSeconds / 60;
}

const unsigned long TimeDisplay::currentSeconds() const {
  return _currentTimeInSeconds % 60;
}
