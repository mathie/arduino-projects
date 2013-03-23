// vim: set ft=arduino:

#ifndef TIME_DISPLAY_H
#define TIME_DISPLAY_H

class LcdArray;

class TimeDisplay {
  public:
  TimeDisplay(LcdArray *lcdArray);

  void refresh();

  private:
  LcdArray *_lcdArray;
  unsigned long _previousTime;
  unsigned long _currentTimeInSeconds;

  bool shouldTick();
  void changeNumber();
  const unsigned long representation();
  const unsigned long currentMinutes();
  const unsigned long currentSeconds();

  static const unsigned long _oneSecond = 1000000;
};

#endif
