# The Hexapod Walking Robot


## Cíle projektu 
- Sestrojit robota z vytisknutých částí a elektronických součástek
- Sestrojit ovladač na ovládání robota
- Zajistit komunikaci mezi robotem a ovladačem
- Naprogramovat robota aby chodil a vykonával různé pohyby

## Zdroj
https://www.thingiverse.com/thing:2513566




#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN 125
#define SERVOMAX 575

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);

  // Inicializace PWM driveru s I2C adresou 0x40
  pwm.begin();
  
  // Nastavení frekvence PWM (případně můžete použít výchozí hodnotu 50 Hz)
  pwm.setPWMFreq(60);  // 60 Hz je obvyklá hodnota pro servomotory
}

void setServoAngle(uint8_t servoNum, int angle) {
  // Funkce pro nastavení úhlu servomotoru přes PWM driver
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(servoNum, 0, pulse);
}

void loop() {
  setServoAngle(1, 100);  
  delay(1000);
  setServoAngle(2, 100);  
  delay(1000);           
  setServoAngle(3, 100); 
  delay(1000); 
  setServoAngle(4, 100);  
  delay(1000);
  setServoAngle(5, 100);  
  delay(1000);
  setServoAngle(6, 100);  
  delay(1000);
  setServoAngle(7, 100);  
  delay(1000);
  setServoAngle(8, 100);  
  delay(1000);
  setServoAngle(9, 100);  
  delay(1000);
  setServoAngle(10, 100);  
  delay(1000);
  setServoAngle(11, 100);  
  delay(1000);

}
