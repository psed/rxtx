#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

Servo myservo;
Servo myservo1;
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(CE_PIN, CSN_PIN);
int command[2];

