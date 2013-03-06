#define count_of(array) (sizeof(array) / sizeof(array[0]))

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

  static const unsigned int _digitOff   = LOW;
  static const unsigned int _digitOn    = HIGH;
  static const unsigned int _segmentOff = HIGH;
  static const unsigned int _segmentOn  = LOW;
};

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

const unsigned int digitPins[] = { 1, 2, 3, 4, NULL };
const unsigned int segmentPins[] = { 5, 6, 7, 8, 9, 10, 11 };
const unsigned int dpSegmentPin = 12;

LcdArray lcdArray(digitPins, segmentPins, dpSegmentPin);

unsigned int randomNumber;

void setup()
{
  randomSeed(analogRead(A0));
  randomNumber = random(1, 2000);
}

void loop()
{
  lcdArray.displayNumber(randomNumber, 0);
}
