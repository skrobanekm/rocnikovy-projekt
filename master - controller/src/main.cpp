//master code
#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX
int buttons = A3;
int data = 0;
 
void setup()
{
   pinMode(buttons,INPUT);
  Serial.begin(38400);
   BTSerial.begin(38400);  
}

void loop()
{
int readAnalog = analogRead(buttons);
if(readAnalog < 150) data = 0;
else data = map(readAnalog,0,1024,1,6);
if(data > -1) {
BTSerial.println(data);
}
    delay(10);
}






