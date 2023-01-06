void setup() 
{
 digitalWrite(13, LOW);
}

void loop() 
{
while(!stop1234());
digitalWrite(13, HIGH);
}
bool stop1234()
{
int sensorValue = analogRead(A0); // read the input on analog pin 0
Serial.println(sensorValue); // print out the value you read
if (sensorValue>650)
  {
    return true;
  }
    return false;
}
