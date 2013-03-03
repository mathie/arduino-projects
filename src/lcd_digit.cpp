#include <Arduino.h>
#include "lcd_digit.h"

LcdDigit::LcdDigit(
  const unsigned int segment_a_pin, const unsigned int segment_b_pin,
  const unsigned int segment_c_pin, const unsigned int segment_d_pin,
  const unsigned int segment_e_pin, const unsigned int segment_f_pin,
  const unsigned int segment_g_pin
) {
  setupNumber(_all,        segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin, segment_e_pin, segment_f_pin, segment_g_pin);
  setupNumber(_numbers[0], segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin, segment_e_pin, segment_f_pin);
  setupNumber(_numbers[1],                segment_b_pin, segment_c_pin);
  setupNumber(_numbers[2], segment_a_pin, segment_b_pin,                segment_d_pin, segment_e_pin,                segment_g_pin);
  setupNumber(_numbers[3], segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin,                               segment_g_pin);
  setupNumber(_numbers[4],                segment_b_pin, segment_c_pin,                               segment_f_pin, segment_g_pin);
  setupNumber(_numbers[5], segment_a_pin,                segment_c_pin, segment_d_pin,                segment_f_pin, segment_g_pin);
  setupNumber(_numbers[6], segment_a_pin,                segment_c_pin, segment_d_pin, segment_e_pin, segment_f_pin, segment_g_pin);
  setupNumber(_numbers[7], segment_a_pin, segment_b_pin, segment_c_pin);
  setupNumber(_numbers[8], segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin, segment_e_pin, segment_f_pin, segment_g_pin);
  setupNumber(_numbers[9], segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin,                segment_f_pin, segment_g_pin);

  setupPins();
}

void LcdDigit::setupNumber(
    unsigned int *segments, const unsigned int a,
    const unsigned int b, const unsigned int c,
    const unsigned int d, const unsigned int e,
    const unsigned int f, const unsigned int g
) {
  segments[0] = a;
  segments[1] = b;
  segments[2] = c;
  segments[3] = d;
  segments[4] = e;
  segments[5] = f;
  segments[6] = g;
  segments[7] = NULL;
}

void LcdDigit::setupPins() const {
  for(const unsigned int *segment = _all; *segment != NULL; segment++) {
    pinMode(*segment, OUTPUT);
  }
  clearAllSegments();
}

void LcdDigit::digitalWriteSegments(const unsigned int segments[], const unsigned int level) const {
  for(const unsigned int *segment = segments; *segment != NULL; segment++) {
    digitalWrite(*segment, level);
  }
}

void LcdDigit::clearSegments(const unsigned int segments[]) const {
  digitalWriteSegments(segments, HIGH);
}

void LcdDigit::clearAllSegments() const {
  clearSegments(_all);
}

void LcdDigit::lightSegments(const unsigned int segments[]) const {
  digitalWriteSegments(segments, LOW);
}

void LcdDigit::displayNumber(const unsigned int number) const {
  clearAllSegments();
  lightSegments(_numbers[number]);
}
