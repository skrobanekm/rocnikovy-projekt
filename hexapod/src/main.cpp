#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_SPIDevice.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 125
#define SERVOMAX 575

int angleToPulse(int ang) {
  int pulse = map(ang,0,180, SERVOMIN,SERVOMAX);  
  Serial.print("Angle: ");Serial.print(ang);
  Serial.print(" pulse: ");Serial.println(pulse);
  return pulse;
}

void setup() {
  Serial.begin(9600);
  Serial.println("12 channel Servo test");

  pwm.begin();

  pwm.setPWMFreq(60);
}

void loop() {
  for(int i=0; i<12; i++){
    for(int angle = 0; angle < 181; angle+=10){
      delay(50);
      pwm.setPWM(i, 0, angleToPulse(angle));
    }
  }
  delay(1000);
}

