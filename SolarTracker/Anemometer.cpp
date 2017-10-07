#include "Anemometer.h"

Anemometer::Anemometer()
{
}

Anemometer::~Anemometer()
{
}

// This is the function that the interrupt calls to increment the rotation count 
void Anemometer::ISR_Rotation() {
  if ((millis() - ContactBounceTime) > 15) { // debounce the switch contact. 
    Rotations++;
    ContactBounceTime = millis();
  }
}

void Anemometer::Init()
{
  Serial.begin(9600);

  pinMode(WindSensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(WindSensorPin), ISR_Rotation, FALLING);

  Serial.println("Davis Wind Speed Test");
  Serial.println("Rotations in km/h");
}

float Anemometer::ReadWindSpeed()
{
  Rotations = 0; // Set Rotations count to 0 ready for calculations 

  sei(); // Enables interrupts 
  delay(3000); // Wait 3 seconds to average 
  cli(); // Disable interrupts 

  WindSpeed = Rotations * 1.207005;

  Serial.print(Rotations); Serial.print("\t\t");
  Serial.println(WindSpeed);

  return WindSpeed;
}
