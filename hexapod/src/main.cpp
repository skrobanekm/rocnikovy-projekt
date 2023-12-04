
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_SPIDevice.h>

#define SERVOMIN 125
#define SERVOMAX 575

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
}

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


void setServoAngle(uint8_t servoNum, int angle) {
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(servoNum, 0, pulse);
}


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

void loop() {
  /*setServoAngle(0, 100);   
  setServoAngle(1, 100);            
  setServoAngle(2, 100);  
  setServoAngle(3, 100);   
  setServoAngle(4, 100);   
  setServoAngle(5, 100);  
  setServoAngle(6, 60);  
  setServoAngle(7, 60);   
  setServoAngle(8, 60);  
  setServoAngle(9, 60);   
  setServoAngle(10, 60);  
  setServoAngle(11, 60);
  delay(1000); */ 
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





