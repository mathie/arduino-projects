// vim: set ft=arduino:

#include "lcd_array.h"

#include <Arduino.h>

const unsigned int LcdArray::_numbers[][LcdArray::_segmentPinCount] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 1, 0, 1, 1 }  // 9
};

const unsigned int LcdArray::_digitOff   = LOW;
const unsigned int LcdArray::_digitOn    = HIGH;
const unsigned int LcdArray::_segmentOff = HIGH;
const unsigned int LcdArray::_segmentOn  = LOW;

LcdArray::LcdArray(const unsigned int digitPins[], const unsigned int segmentPins[], const unsigned int dpSegmentPin, const unsigned int lDigitPin, const unsigned int lSegmentPins[])
  : _digitPins(digitPins), _segmentPins(segmentPins), _dpSegmentPin(dpSegmentPin), _lDigitPin(lDigitPin), _lSegmentPins(lSegmentPins)
{
  for(_digitPinCount = 0; _digitPins[_digitPinCount] != NULL; _digitPinCount++);
  for(_lSegmentPinCount = 0; _lSegmentPins[_lSegmentPinCount] != NULL; _lSegmentPinCount++);

  setup();
}

void LcdArray::setup() {
  for(unsigned int i = 0; i < _digitPinCount; i++) {
    pinMode(_digitPins[i], OUTPUT);
    digitalWrite(_digitPins[i], _digitOff);
  }

  pinMode(_lDigitPin, OUTPUT);
  digitalWrite(_lDigitPin, _digitOff);

  for(unsigned int i = 0; i < _segmentPinCount; i++) {
    pinMode(_segmentPins[i], OUTPUT);
    digitalWrite(_segmentPins[i], _segmentOff);
  }

  pinMode(_dpSegmentPin, OUTPUT);
  digitalWrite(_dpSegmentPin, _segmentOff);

  for(unsigned int i = 0; i < _lSegmentPinCount; i++) {
    pinMode(_lSegmentPins[i], OUTPUT);
    digitalWrite(_lSegmentPins[i], _segmentOff);
  }
}

void LcdArray::changeNumber(const unsigned int number, const bool *lSegments, const int dotPosition) {
  unsigned int digits[_digitPinCount];

  bool previousDigitIsSignificant = false;
  for(unsigned int i = 0; i < _digitPinCount; i++) {
    unsigned int power = (unsigned int)pow((double)10, (double)(_digitPinCount - i - 1));
    digits[i] = (number / power) % 10;

    _segments[i] = _numbers[digits[i]];

    previousDigitIsSignificant = _significantDigit[i] = previousDigitIsSignificant || (digits[i] > 0);
  }

  // Last digit is always significant or 0 doesn't show up!
  _significantDigit[_digitPinCount - 1] = true;

  _dotPosition = dotPosition;

  for(unsigned int i = 0; i < _lSegmentPinCount; i++) {
    _lSegments[i] = lSegments[i];
  }

  refreshNumber();
}

void LcdArray::refreshDigits() {
  for(unsigned int segment = 0; segment < _segmentPinCount; segment++) {
    digitalWrite(_segmentPins[segment], _segmentOn);

    for(unsigned int digit = 0; digit < _digitPinCount; digit++) {
      if(_significantDigit[digit] && _segments[digit][segment]) {
        digitalWrite(_digitPins[digit], _digitOn);
      }
    }

    for(unsigned int digit = 0; digit < _digitPinCount; digit++) {
      digitalWrite(_digitPins[digit], _digitOff);
    }

    digitalWrite(_segmentPins[segment], _segmentOff);
  }
}

void LcdArray::refreshDecimalPoint() {
  digitalWrite(_dpSegmentPin, _segmentOn);

  for(unsigned int digit = 0; digit < _digitPinCount; digit++) {
    if(digit == _dotPosition) {
      digitalWrite(_digitPins[digit], _digitOn);
    }
  }

  for(unsigned int digit = 0; digit < _digitPinCount; digit++) {
    digitalWrite(_digitPins[digit], _digitOff);
  }

  digitalWrite(_dpSegmentPin, _segmentOff);
}

void LcdArray::refreshAdditionalLights() {
  for(unsigned int segment = 0; segment < _lSegmentPinCount; segment++) {
    digitalWrite(_lSegmentPins[segment], _segmentOn);

    for(unsigned int digit = 0; digit < _digitPinCount; digit++) {
      digitalWrite(_lDigitPin, _digitOn);
    }

    digitalWrite(_lDigitPin, _digitOff);

    digitalWrite(_segmentPins[segment], _segmentOff);
  }
}

void LcdArray::refreshNumber() {
  refreshDigits();
  refreshDecimalPoint();
  refreshAdditionalLights();
}
