#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define CE_PIN   9
#define CSN_PIN 10

Servo myservo;
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(CE_PIN, CSN_PIN);
int joystick[1];

void setup()
{
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  myservo.attach(4); 
}

void loop() 
{
  if (radio.available())
  {
    bool done = false;
    while (!done)
    {
     done = radio.read(joystick, sizeof(joystick));
     myservo.write(joystick[0]/10);
    }
  }
}
