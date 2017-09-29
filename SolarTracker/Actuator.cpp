#include "Actuator.h"

Actuator::Actuator()
{
}

void Actuator::Setup(int pinPush, int pinPull)
{
  _pinPush = pinPush;
  _pinPull = pinPull;
  pinMode(_pinPush, OUTPUT);//set relay as an output
  pinMode(_pinPull, OUTPUT);//set relay as an output
}

void Actuator::Push()
{
  digitalWrite(_pinPush, HIGH);
  digitalWrite(_pinPull, HIGH);//Deactivate both relays to brake the motor
  delay(2000);// wait 2 seconds
}

void Actuator::Pull()
{
  digitalWrite(_pinPush, LOW);
  digitalWrite(_pinPull, HIGH);//Activate the relay one direction, they must be different to move the motor
  delay(2000); // wait 2 seconds
}

void Actuator::Break()
{
  digitalWrite(_pinPush, HIGH);
  digitalWrite(_pinPull, HIGH);//Deactivate both relays to brake the motor
  delay(2000);// wait 2 seconds
}


