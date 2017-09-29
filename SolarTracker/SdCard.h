#ifndef _SDCARD_h
#define _SDCARD_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include <SPI.h>
#include <SD.h>
#else
#include "WProgram.h"
#endif
class SdCard
{
public:
  SdCard();
  ~SdCard();
  void Read(char fileName[]);
  void Write(char fileName[]);
  void Setup();
private:
  File myFile;
};
#endif
