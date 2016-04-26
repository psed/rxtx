const uint64_t pipe = 0xE8E8F0F0E1LL;

#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);

void initRadio()
{
  radio.begin();
  radio.openWritingPipe(pipe);
}
