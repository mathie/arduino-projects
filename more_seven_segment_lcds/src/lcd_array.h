#ifndef LCD_ARRAY_H
#define LCD_ARRAY_H

class LcdArray {
  public:
  LcdArray(const unsigned int digitPins[], const unsigned int segmentPins[], const unsigned int dpSegmentPin);

  void changeNumber(const unsigned int number, const int dotPosition = -1);
  void refreshNumber();

  private:
  void setup();

  void refreshDigits();
  void refreshDecimalPoint();

  const unsigned int *_digitPins;
  const unsigned int *_segmentPins;
  const unsigned int _dpSegmentPin;

  // FIXME: This is the only place that still assumes a maximum of 4 digits.
  const unsigned int *_segments[4];
  unsigned int _significantDigit[4];
  unsigned int _dotPosition;

  unsigned int _digitPinCount;

  static const unsigned int _segmentPinCount = 7;
  static const unsigned int _numbers[][_segmentPinCount];

  static const unsigned int _digitOff;
  static const unsigned int _digitOn;
  static const unsigned int _segmentOff;
  static const unsigned int _segmentOn;
};

#endif
