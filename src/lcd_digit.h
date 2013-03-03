#ifndef LCD_DIGIT_H
#define LCD_DIGIT_H

#include <stddef.h>

class LcdDigit {
  public:
  LcdDigit(
    const unsigned int segment_a_pin,
    const unsigned int segment_b_pin,
    const unsigned int segment_c_pin,
    const unsigned int segment_d_pin,
    const unsigned int segment_e_pin,
    const unsigned int segment_f_pin,
    const unsigned int segment_g_pin
  );

  void displayNumber(const unsigned int number) const;
  void clearNumber() const;

  private:
  void setupNumber(unsigned int segments[], const unsigned int a = NULL, const unsigned int b = NULL, const unsigned int c = NULL, const unsigned int d = NULL, const unsigned int e = NULL, const unsigned int f = NULL, const unsigned int g = NULL);
  void setupPins() const;
  void digitalWriteSegments(const unsigned int segments[], const unsigned int level) const;
  void clearSegments(const unsigned int segments[]) const;
  void clearAllSegments() const;
  void lightSegments(const unsigned int segments[]) const;

  unsigned int _all[8];
  unsigned int _numbers[10][8];
};

#endif
