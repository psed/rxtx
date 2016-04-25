#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include "constants.h"

void setup()
{
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  myservo.attach(0); 
  myservo1.attach(1);
}

void loop() 
{
  if (radio.available())
  {
    bool done = false;
    while (!done)
    {
     done = radio.read(command, sizeof(command));
     myservo.write(command[0]);
     myservo1.write(command[1]);
    }
  }
}
