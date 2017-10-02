#ifndef _H12_h
#define _H12_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include <SoftwareSerial.h>
#else
#include "WProgram.h"
#endif

#pragma once
class H12
{
public:
  H12();
  ~H12();
  void Init();
  void Read();
  void Write();
private: 

};
#endif
