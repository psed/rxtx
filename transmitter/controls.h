int mapRawPotentiometerValueToServoValue(int potentiometerValue)
{
  return map(potentiometerValue, 0, 1023, 0, 180);  
}
