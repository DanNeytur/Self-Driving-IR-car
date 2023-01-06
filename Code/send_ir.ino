#include <IRremote.h>

IRsend irsend;

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  digitalWrite(3,HIGH);
}

void loop() {

      irsend.sendNEC(0xA1B2C3,32); 
      delay(50);

}
