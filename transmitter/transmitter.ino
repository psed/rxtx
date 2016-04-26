#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include "constants.h"
#include "controls.h"
#include "display.h"
#include "radio.h"

void setup()
{  
  initDisplay();
  initRadio();
}

void loop()
{
  readSensors(&rawValues[2]);
  command[0] = mapRawPotentiometerValueToServoValue(rawValues[0]);
  command[1] = mapRawPotentiometerValueToServoValue(rawValues[1]);
  radio.write(command, sizeof(command));
}
