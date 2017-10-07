#ifndef _ANEMOMETER_H
#define _ANEMOMETER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include <math.h> 
#else
#include "WProgram.h"
#endif
class Anemometer
{
public:
  Anemometer();
  ~Anemometer();
  void Anemometer::Init();
  float Anemometer::ReadWindSpeed();
private:
  #define WindSensorPin (2) // The pin location of the anemometer sensor 
  static unsigned long Rotations; // cup rotation counter used in interrupt routine 
  static unsigned long ContactBounceTime; // Timer to avoid contact bounce in interrupt routine 
  float WindSpeed; // speed km/h 
  static void ISR_Rotation();
};
#endif
