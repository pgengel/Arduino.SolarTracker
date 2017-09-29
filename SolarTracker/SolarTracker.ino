#include <Wire.h>
#include "Actuator.h"

Actuator actuator;
// the setup function runs once when you press reset or power the board
void setup() {
  actuator.Setup(13, 8); 
}

// the loop function runs over and over again forever
void loop() {
  actuator.Pull();
  actuator.Break();
  actuator.Push();
}