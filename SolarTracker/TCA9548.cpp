#include "TCA9548.h"

void TCA9548::tcaselect(uint8_t i) 
{
  if (i > 7) return;

  Wire.beginTransmission(0x70);
  Wire.write(1 << i);
  Wire.endTransmission();
}

TCA9548::TCA9548()
{
  while (!Serial);
  delay(1000);

  Wire.begin();

  Serial.begin(9600);
  Serial.println("\nTCAScanner ready!");

}

void TCA9548::Write(int tsel)
{
  tcaselect(tsel);
  Serial.print("TCA Port #"); Serial.println(tsel);

  for (uint8_t addr = 0; addr <= 127; addr++) 
  {
    if (addr == 0x70) continue;

    uint8_t data;
    if (!twi_writeTo(addr, &data, 0, 1, 1)) {
      Serial.print("Found I2C 0x");  Serial.println(addr, HEX);
    }
  }

  Serial.println("\ndone");
}

TCA9548::~TCA9548()
{
}
