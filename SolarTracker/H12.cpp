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

void H12::Read() 
{
  if (Serial.available() > 0)//Read from serial monitor and send over HC-12
  {
    String input = Serial.readString();
    mySerial.println(input);
  }
}

void H12::Write()
{
  if (mySerial.available() > 1) //Read from HC-12 and send to serial monitor
  {    
    String input = mySerial.readString();
    Serial.println(input);
  }
}
