#include "H12.h"

SoftwareSerial mySerial(2, 3); //RX, TX

H12::H12()
{

}


H12::~H12()
{
}

void H12::Init()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  mySerial.begin(9600);
}

String H12::Read()
{
  if (Serial.available() > 0)//Read from serial monitor and send over HC-12
  {
    String input = Serial.readString();
    mySerial.println(input);
    return input;
  } 
}

void H12::Write(int transmit)
{
   Serial.println(transmit);
}
