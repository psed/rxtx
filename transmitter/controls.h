void readSensors(int *rawValues)
{
  rawValues[0] = analogRead(JOYSTICK_X);
  rawValues[1] = analogRead(JOYSTICK_Y);
}

int mapRawPotentiometerValueToServoValue(int potentiometerValue)
{
  return map(potentiometerValue, 0, 1023, 0, 180);  
}
