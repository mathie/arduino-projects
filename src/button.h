#ifndef BUTTON_H
#define BUTTON_H

class Button {
  public:
  Button(const unsigned int inputPin);

  const bool isUpdated();
  const bool isPressed();

  private:
  const unsigned int readValue();

  const unsigned int _inputPin;
  unsigned int _previousState, _currentState;
};

#endif
