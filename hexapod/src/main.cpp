#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_SPIDevice.h>

#define SERVOMIN 125
#define SERVOMAX 575
int stage = 2;

 int values [2] [12] = {
  {90,90,90,90,90,90,50,50,50,50,50,50},
 {90,90,90,90,90,90,50,100,50,100,50,100},
// {90,50,90,90,140,90,30,40,40,40,40,30},
  //{90,90,90,90,50,90,90,40,40,40,40,150},
   //{90,140,90,90,50,90,40,40,40,40,40,40},

// 0   1  2  3   4  5 | 6   7  8  9  10 11 
 


/*
   {0,130},  
   {2,130},
   {4,80}, 
   {3,130},  
   {5,130},
   {1,80},

    {6,60},
  {8,60},  
  {10,60},
  {7,100},
  {9,100},  
  {11,100},

   {0,80},
  {2,80},
  {4,130},
  {3,80},
  {5,80},
  {1,130}
*/


 };


/*
test všech serv.

int angleToPulse(int ang) {
  int pulse = map(ang,0,180, SERVOMIN,SERVOMAX);  
  Serial.print("Angle: ");Serial.print(ang);
  Serial.print(" pulse: ");Serial.println(pulse);
  return pulse;
}

void loop() {
  for(int i=0; i<12; i++){
    for(int angle = 0; angle < 181; angle+=10){
      delay(50);
      pwm.setPWM(i, 0, angleToPulse(angle));
    }
  }
  delay(1000);
}*/






SoftwareSerial BTserial(2, 3); // RX | TX
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
int data = 0;




void setServoAngle(uint8_t servoNum, int angle) {
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(servoNum, 0, pulse);
}


void setup()
{
  Serial.begin(38400);
  BTserial.begin(38400);
  pwm.begin();
  pwm.setPWMFreq(60);     

  data = 0;

}
 
void loop()
{
   if(BTserial.available() > 0) {
    int read = BTserial.read();
    data = read - 48;
     Serial.println(data,DEC);
  

}
if(data == 0) {
setServoAngle(0,90);
setServoAngle(1,90);
setServoAngle(2,90);
setServoAngle(3,90);
setServoAngle(4,90);
setServoAngle(5,90);
setServoAngle(6,50);
setServoAngle(7,50);
setServoAngle(8,50);
setServoAngle(9,50);
setServoAngle(10,50);
setServoAngle(11,50);
}


if(data == 1) {
    BTserial.end();
  setServoAngle(6,100);
  setServoAngle(8,100);  
  setServoAngle(10,100);
  delay(1000);
  setServoAngle(0,130);
  setServoAngle(2,130);
  setServoAngle(4,80);
  setServoAngle(3,130);
  setServoAngle(5,130);
  setServoAngle(1,80);
  delay(1000);
  setServoAngle(6,50);
  setServoAngle(8,50);  
  setServoAngle(10,50);
  setServoAngle(7,100);
  setServoAngle(9,100);  
  setServoAngle(11,100);
  delay(1000);
  setServoAngle(0,80);
  setServoAngle(2,80);
  setServoAngle(4,130);
  setServoAngle(3,80);
  setServoAngle(5,80);
  setServoAngle(1,130);
  delay(1000);
  setServoAngle(7,50);
  setServoAngle(9,50);  
  setServoAngle(11,50);
  delay(1000);
  data = 0;
      BTserial.begin(38400);
  }
if(data == 2) {
    BTserial.end();
  setServoAngle(6, 180);             
  setServoAngle(7, 180);
  setServoAngle(8, 180);
  setServoAngle(9, 180);
  setServoAngle(10, 180);
  setServoAngle(11, 180);
  for (size_t i = 0; i < 7; i++)
  {
  setServoAngle(0, 100);  
  setServoAngle(1, 100);  
  setServoAngle(2, 100);  
  setServoAngle(3, 100);  
  setServoAngle(4, 100);  
  setServoAngle(5, 100);  
  delay(500);
  setServoAngle(0, 50);  
  setServoAngle(1, 50);  
  setServoAngle(2, 50);  
  setServoAngle(3, 50);  
  setServoAngle(4, 50);  
  setServoAngle(5, 50); 
  delay(500);
  }
  data = 0;
      BTserial.begin(38400);
  }


if(data == 5) {
    BTserial.end();
  setServoAngle(5, 140);  
  delay(10);           
  setServoAngle(2, 60);
  delay(10);
  setServoAngle(4, 140);
  delay(10);
  setServoAngle(3, 60);
  delay(10);
  for (size_t i = 0; i < 7; i++)
  {
    setServoAngle(9, 100);  
  delay(100);
  setServoAngle(10, 100);  
  delay(100);
  setServoAngle(9, 180);  
  delay(100);
  setServoAngle(10, 180);  
  delay(100);
  }
  data = 0;
      BTserial.begin(38400);
  }
 




}




