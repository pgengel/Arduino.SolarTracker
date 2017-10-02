#ifndef _RTC_h
#define _RTC_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include <Wire.h>
#include "TimeLib.h"
#include "DS1307RTC.h"
#else
#include "WProgram.h"
#endif
class RTC
{
public:
  RTC();
  ~RTC();
  void Init();
  void GetCurrentTime();
private:
  void print2digits(int number);
};
#endif
