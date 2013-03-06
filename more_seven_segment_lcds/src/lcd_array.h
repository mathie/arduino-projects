#ifndef LCD_ARRAY_H
#define LCD_ARRAY_H

class LcdArray {
  public:
  LcdArray(const unsigned int digitPins[], const unsigned int segmentPins[], const unsigned int dpSegmentPin);
  void displayNumber(const unsigned int number, const int dotPosition = -1);

  private:
  void setup();

  const unsigned int *_digitPins;
  const unsigned int *_segmentPins;
  const unsigned int _dpSegmentPin;

  unsigned int _digitPinCount;

  static const unsigned int _segmentPinCount = 7;
  static const unsigned int _numbers[][_segmentPinCount];

  static const unsigned int _digitOff;
  static const unsigned int _digitOn;
  static const unsigned int _segmentOff;
  static const unsigned int _segmentOn;
};

#endif
