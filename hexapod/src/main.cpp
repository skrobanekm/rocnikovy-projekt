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


/*
mávaní předními nohami

void loop() {
  setServoAngle(0, 140);  
  delay(10);           
  setServoAngle(3, 60);
  delay(10);
  setServoAngle(5, 140);
  delay(10);
  setServoAngle(4, 60);
  delay(10);
  setServoAngle(11, 100);  
  delay(100);
  setServoAngle(10, 100);  
  delay(100);
  setServoAngle(11, 180);  
  delay(100);
  setServoAngle(10, 180);  
  delay(100);
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
    //int read = BTserial.read();
  //  data = read - 48;
    // Serial.println(data,DEC);
  

}
/*
 for (byte i = 0; i < 12;i++) {
 // setServoAngle(i,values[data][i]);
 Serial.println(data);
 }

 delay(1000);
 data++;
 if(data > 1) data = 0;
 */

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
  setServoAngle(6,60);
  setServoAngle(8,60);  
  setServoAngle(10,60);
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
  setServoAngle(7,60);
  setServoAngle(9,60);  
  setServoAngle(11,60);
  delay(1000);




}




