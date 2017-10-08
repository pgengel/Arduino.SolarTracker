// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include <RTClib.h>
#include "SdCard.h"
#include <math.h> 

#define SOLARDATAFILE "solardatafile.csv"
#define WindSensorPin (2) // The pin location of the anemometer sensor 

volatile unsigned long Rotations; // cup rotation counter used in interrupt routine 
volatile unsigned long ContactBounceTime; // Timer to avoid contact bounce in interrupt routine 

float WindSpeed; // speed miles per hour 

RTC_DS1307 rtc;
SdCard sdCard;

void setup() {
  TimeInit();
  sdCard.Init();
}

void loop() {
  //The master arduino must read the current time from RTC.
  DateTime now = rtc.now();

  //The master arduino must read deg tracking from an SD card.
  //The master arduino must choose the correct angle based on the time of day and the angle on the SD card.
  int angle = sdCard.GetAngle(SOLARDATAFILE, now);

  //The master arduino must measure the wind speed.


  delay(3000);
}



void TimeInit()
{
  while (!Serial); // for Leonardo/Micro/Zero

  Serial.begin(57600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}