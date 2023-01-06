#include "IRremote.h"
#include <AFMotor.h>
#define IR_USE_TIMER3
AF_DCMotor motor_1(1);
AF_DCMotor motor_2(2);
AF_DCMotor motor_3(3);
AF_DCMotor motor_4(4);
const int RECV_PIN = 16;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
  Serial.begin(9600);
  Serial.println("serial monitor:");
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(22, OUTPUT);
  pinMode(28, OUTPUT);
  digitalWrite(22, HIGH);
  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  motor_3.run(RELEASE);
  motor_4.run(RELEASE);
}

void loop() 
{
  if (!digitalRead(28))
  {
    digitalWrite(22, HIGH); //red LED off
    if (irrecv.decode(&results))
      {
        Serial.println(results.value, HEX);
        if (results.value == 0xA1B2C3)
          {
            digitalWrite(22, LOW); //red LED on
            Serial.println("FORWARD1234");
            FORWARD1234();
          }
         else
          {
            search();
            Serial.println("search()");
          }
          irrecv.resume();
           delay(500);
       }
      else
       {
        search();
        Serial.println("search()");
        }
       }
      else
       {
        RELEASE1234();
        while(1);
       }
}

void FORWARD1234()
{
motor_1.run(FORWARD);
motor_2.run(FORWARD);
motor_3.run(BACKWARD);
motor_4.run(BACKWARD);
motor_1.setSpeed(255);
motor_3.setSpeed(255);
motor_2.setSpeed(255);
motor_4.setSpeed(255);
delay(400);
}

void RELEASE1234()
{
motor_1.run(RELEASE);
motor_2.run(RELEASE);
motor_3.run(RELEASE);
motor_4.run(RELEASE);
}

void search()
{
motor_1.run(FORWARD);
motor_2.run(FORWARD);
motor_3.run(FORWARD);
motor_4.run(FORWARD);
motor_1.setSpeed(180);
motor_3.setSpeed(180);
motor_2.setSpeed(180);
motor_4.setSpeed(180);
}
  
  
 
