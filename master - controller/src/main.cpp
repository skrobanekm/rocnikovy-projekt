
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
   int readAnalong = analogRead(buttons);
data = map(readAnalong,200,1024,0,5);
if(data > -1) {
//BTSerial.println(data);
}
    delay(10);
}



