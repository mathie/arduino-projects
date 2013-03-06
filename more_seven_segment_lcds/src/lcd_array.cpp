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

LcdArray::LcdArray(const unsigned int digitPins[], const unsigned int segmentPins[], const unsigned int dpSegmentPin)
  : _digitPins(digitPins), _segmentPins(segmentPins), _dpSegmentPin(dpSegmentPin)
{
  for(_digitPinCount = 0; _digitPins[_digitPinCount] != NULL; _digitPinCount++);

  setup();
}

void LcdArray::setup() {
  for(unsigned int i = 0; i < _digitPinCount; i++) {
    pinMode(_digitPins[i], OUTPUT);
    digitalWrite(_digitPins[i], _digitOff);
  }

  for(unsigned int i = 0; i < _segmentPinCount; i++) {
    pinMode(_segmentPins[i], OUTPUT);
    digitalWrite(_segmentPins[i], _segmentOff);
  }

  pinMode(_dpSegmentPin, OUTPUT);
  digitalWrite(_dpSegmentPin, _segmentOff);
}

void LcdArray::displayNumber(const unsigned int number, const int dotPosition) {
  unsigned int digits[4], significantDigit[4];
  const unsigned int *segments[4];

  digits[0] = (number / 1000) % 10;
  digits[1] = (number /  100) % 10;
  digits[2] = (number /   10) % 10;
  digits[3] = (number /    1) % 10;

  segments[0] = _numbers[digits[0]];
  segments[1] = _numbers[digits[1]];
  segments[2] = _numbers[digits[2]];
  segments[3] = _numbers[digits[3]];

  significantDigit[0] = (digits[0] > 0);
  significantDigit[1] = significantDigit[0] || (digits[1] > 0);
  significantDigit[2] = significantDigit[1] || (digits[2] > 0);
  significantDigit[3] = significantDigit[2] || (digits[3] > 0);

  for(unsigned int segment = 0; segment < _segmentPinCount; segment++) {
    digitalWrite(_segmentPins[segment], _segmentOn);

    for(unsigned int digit = 0; digit < _digitPinCount; digit++) {
      if(significantDigit[digit] && segments[digit][segment]) {
        digitalWrite(_digitPins[digit], _digitOn);
      }
    }

    for(unsigned int digit = 0; digit < _digitPinCount; digit++) {
      digitalWrite(_digitPins[digit], _digitOff);
    }

    digitalWrite(_segmentPins[segment], _segmentOff);
  }

  digitalWrite(_dpSegmentPin, _segmentOn);

  for(unsigned int digit = 0; digit < _digitPinCount; digit++) {
    if(digit == dotPosition) {
      digitalWrite(_digitPins[digit], _digitOn);
    }
  }

  for(unsigned int digit = 0; digit < _digitPinCount; digit++) {
    digitalWrite(_digitPins[digit], _digitOff);
  }

  digitalWrite(_dpSegmentPin, _segmentOff);
}
