#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "constants.h"
#include "controls.h"

void setup()
{  
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop()
{
  rawJoystick0 = analogRead(JOYSTICK_X);
  rawJoystick1 = analogRead(JOYSTICK_Y);
  command[0] = mapRawPotentiometerValueToServoValue(rawJoystick0);
  command[1] = mapRawPotentiometerValueToServoValue(rawJoystick1);
  radio.write(command, sizeof(command));
}
