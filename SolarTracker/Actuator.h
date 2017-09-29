// Actuator.h

#ifndef _ACTUATOR_h
#define _ACTUATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
class Actuator
{
public:
  Actuator();
  void Setup(int pinPush, int pinPull);
  void Push();
  void Pull();
  void Break();

private:
  int _pinPush = 13 , _pinPull = 8;
};

#endif

