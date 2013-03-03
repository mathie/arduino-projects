#ifndef LCD_DIGIT_H
#define LCD_DIGIT_H

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

  void displayNumber(const unsigned int number);
  void clearNumber();

  private:
  void setupNumber(unsigned int *segments, const unsigned int a = NULL, const unsigned int b = NULL, const unsigned int c = NULL, const unsigned int d = NULL, const unsigned int e = NULL, const unsigned int f = NULL, const unsigned int g = NULL);
  void setupPins();
  void digitalWriteSegments(const unsigned int *segments, const unsigned int level);
  void clearSegments(const unsigned int *segments);
  void clearAllSegments();
  void lightSegments(const unsigned int segments[]);

  unsigned int _all[8], _zero[8], _one[8], _two[8], _three[8], _four[8],
    _five[8], _six[8], _seven[8], _eight[8], _nine[8];

  unsigned int *_numbers[10];
};

#endif
