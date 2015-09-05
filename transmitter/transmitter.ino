#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN 9
#define CSN_PIN 10
#define JOYSTICK_X A0

const uint64_t pipe = 0xE8E8F0F0E1LL;
int joystick[1];

RF24 radio(CE_PIN, CSN_PIN);

void setup()
{  
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop()
{
  joystick[0] = analogRead(JOYSTICK_X);
  radio.write(joystick, sizeof(joystick));
}
