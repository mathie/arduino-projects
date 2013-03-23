// vim: set ft=arduino:

#ifndef TIME_DISPLAY_H
#define TIME_DISPLAY_H

class LcdArray;

class TimeDisplay {
  public:
  TimeDisplay(LcdArray *lcdArray);

  void reset();
  void toggle();
  void stop();
  void start();
  void refresh();

  private:
  LcdArray *_lcdArray;
  unsigned long _previousTime;
  unsigned long _currentTimeInSeconds;
  bool _isRunning;

  bool shouldTick();
  void changeNumber() const;
  const unsigned long representation() const;
  const unsigned long currentMinutes() const;
  const unsigned long currentSeconds() const;

  static const unsigned long _oneSecond = 1000000;
};

#endif
