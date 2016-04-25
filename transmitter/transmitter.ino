#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "constants.h"

RF24 radio(CE_PIN, CSN_PIN);

void setup()
{  
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop()
{
  rawJoystick0 = analogRead(JOYSTICK_X);
  rawJoystick1 = analogRead(JOYSTICK_Y);
  command[0] = map(rawJoystick0, 0, 1023, 0, 180);
  command[1] = map(rawJoystick1, 0, 1023, 0, 180);
  radio.write(command, sizeof(command));
}
