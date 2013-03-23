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

  static const unsigned long _oneSecond = 1000000;
};

#endif
