#ifndef _SDCARD_h
#define _SDCARD_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include <SPI.h>
#include <SD.h>
#include <RTClib.h>
#else
#include "WProgram.h"
#endif
class SdCard
{
public:
  SdCard();
  ~SdCard();
  int SdCard::GetAngle(char fileName[], DateTime now);
  void Write(char fileName[]);
  void Init();
private:
  File myFile;
  char fileContents[128]; // Probably can be smaller
  byte index = 0;
  void SdCard::FindAngle(int time);
};
#endif
