#define count_of(array) (sizeof(array) / sizeof(array[0]))

const unsigned int digitPins[] = { 1, 2, 3, 4 };
const unsigned int segmentPins[] = { 5, 6, 7, 8, 9, 10, 11 };
const unsigned int dotPin = 12;

// Digit is the cathode, segment is the anode.
const unsigned int digitOff   = LOW;
const unsigned int digitOn    = HIGH;
const unsigned int segmentOff = HIGH;
const unsigned int segmentOn  = LOW;

void setup()
{
  for(unsigned int i = 0; i < count_of(digitPins); i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], digitOff);
  }
  for(unsigned int i = 0; i < count_of(segmentPins); i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], segmentOff);
  }
  pinMode(dotPin, OUTPUT);
  digitalWrite(dotPin, segmentOff);
}

void loop()
{

  const unsigned int numbers[][7] = {
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

  const unsigned int *digits[] = {
    numbers[3],
    numbers[1],
    numbers[4],
    numbers[1]
  };

  const unsigned int dotPosition = 0;

  for(unsigned int segment = 0; segment < count_of(segmentPins); segment++) {
    digitalWrite(segmentPins[segment], segmentOn);

    for(unsigned int digit = 0; digit < count_of(digitPins); digit++) {
      if(digits[digit][segment]) {
        digitalWrite(digitPins[digit], digitOn);
      }
    }

    for(unsigned int digit = 0; digit < count_of(digitPins); digit++) {
      digitalWrite(digitPins[digit], digitOff);
    }

    digitalWrite(segmentPins[segment], segmentOff);
  }

  digitalWrite(dotPin, segmentOn);

  for(unsigned int digit = 0; digit < count_of(digitPins); digit++) {
    if(digit == dotPosition) {
      digitalWrite(digitPins[digit], digitOn);
    }
  }

  for(unsigned int digit = 0; digit < count_of(digitPins); digit++) {
    digitalWrite(digitPins[digit], digitOff);
  }

  digitalWrite(dotPin, segmentOff);
}
