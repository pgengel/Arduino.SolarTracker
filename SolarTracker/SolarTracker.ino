// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include <RTClib.h>
#include "SdCard.h"
#include <math.h> 
#include "H12.h"
#include <SoftwareSerial.h>
#include "TCA9548.h"
#include "Angle.h"
#include "Actuator.h"

#define SOLARDATAFILE "solardatafile.csv"
#define WindSensorPin (2) // The pin location of the anemometer sensor 

volatile unsigned long Rotations; // cup rotation counter used in interrupt routine 
volatile unsigned long ContactBounceTime; // Timer to avoid contact bounce in interrupt routine 

float WindSpeed; // speed miles per hour 

RTC_DS1307 rtc;
SdCard sdCard;
H12 h12;
Angle measureAngle;
Actuator actuator;

void setup() 
{
  Serial.begin(9600);
  TimeInit();
  sdCard.Init();

  //The slave arduino must have a starting position of 90 deg.

  AnemometerInit();
  h12.Init();
  measureAngle.Init();
  actuator.Init(13, 8);
}

void loop() {
  //The master arduino must read the current time from RTC.
  DateTime now = rtc.now();

  //The master arduino must read deg tracking from an SD card.
  //The master arduino must choose the correct angle based on the time of day and the angle on the SD card.
  int angle = sdCard.GetAngle(SOLARDATAFILE, now);

  //The master arduino must measure the wind speed.
  GetWindSpeed();//global variable

  //The master arduino must send the desired angle to the slave arduino using H12 every 10 sec.
  h12.Write(angle);

  //The slave arduino must read desired angle from wireless H12
  String desiredAngle = h12.Read();

  //The slave arduino must measure the current angle from the accelor for each device.
  double actualAngle = measureAngle.GetAngle();

  //The slave arduino must adjust the panel to the desired angle to 2 deg.
  double difference = desiredAngle.toDouble() - actualAngle;
  if (difference > 0)
  {
    actuator.Pull();
  }
  if (difference < 0)
  {
    actuator.Push();
  }

  delay(3000);
}

// This is the function that the interrupt calls to increment the rotation count 
void isr_rotation() {

  if ((millis() - ContactBounceTime) > 15) { // debounce the switch contact. 
    Rotations++;
    ContactBounceTime = millis();
  }

}

void AnemometerInit()
{
  pinMode(WindSensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(WindSensorPin), isr_rotation, FALLING);

  Serial.println("Wind Speed Test");
  Serial.println("Rotations\tMPH");
}

void GetWindSpeed()
{
  //The master arduino must measure the wind speed.
  Rotations = 0; // Set Rotations count to 0 ready for calculations 

  sei(); // Enables interrupts 
  delay(3000); // Wait 3 seconds to average 
  cli(); // Disable interrupts 

  WindSpeed = Rotations * 1.207005;

  Serial.print(Rotations); Serial.print("\t\t");
  Serial.println(WindSpeed);
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