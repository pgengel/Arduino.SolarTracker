#ifndef _TCA9548_h
#define _TCA9548_h


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include "Wire.h"
extern "C" {
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}
#else
#include "WProgram.h"
#endif
class TCA9548
{
public:
  TCA9548();
  ~TCA9548();
  void Write(int tsel);
private:
  void tcaselect(uint8_t i);
};
#endif

