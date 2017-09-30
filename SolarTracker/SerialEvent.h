#ifndef _SERIALEVENT_h
#define _SERIALEVENT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include <SPI.h>
#include <SD.h>
#else
#include "WProgram.h"
#endif
class SerialEvent
{
public:
  SerialEvent::SerialEvent();
  SerialEvent::~SerialEvent();
  void SerialEvent::Setup();
  void SerialEvent::Read();
  void SerialEvent::Send();
private:
  String inputString = "";         // a String to hold incoming data
  boolean stringComplete = false;  // whether the string is complete
};
#endif
