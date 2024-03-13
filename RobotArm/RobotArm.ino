#include <Servo.h>

//** servo 1 settings
Servo base; 
const int basePotPin =A0;
const int basePin = 3;// Must use PWM enabled pin
int baseValue;
//** servo 1 settings END

//** servo 2 settings
Servo joint1; 
const int joint1PotPin =A1;
const int joint1Pin = 5;// Must use PWM enabled pin
int joint1Value;
//** servo 1 settings END

Servo joint2; 
const int joint2PotPin =A2;
const int joint2Pin = 6;// Must use PWM enabled pin
int joint2Value;

Servo joint3; 
const int joint3PotPin =A3;
const int joint3Pin = 9;// Must use PWM enabled pin
int joint3Value;

Servo joint4; 
const int joint4PotPin =A4;
const int joint4Pin = 10;// Must use PWM enabled pin
int joint4Value;

Servo clamp;
const int clampPin = 11;

void Clamp(bool on){
  if(on){
    clamp.write(0);
  }else{
    clamp.write(173);
  }
  delay(5);
}

void Manual(){ //return array pos

   //Robojax.com multiple servo
  baseValue = analogRead(basePotPin); 
  baseValue = map(baseValue, 0, 1023, 0, 180);
  base.write(baseValue);

  joint1Value = analogRead(joint1PotPin); 
  joint1Value = map(joint1Value, 0, 1023, 80, 140);
  joint1.write(joint1Value);

  joint2Value = analogRead(joint2PotPin); 
  joint2Value = map(joint2Value, 0, 1023, 40, 160);
  joint2.write(joint2Value);

  joint3Value = analogRead(joint3PotPin); 
  joint3Value = map(joint3Value, 0, 1023, 0, 180);
  joint3.write(joint3Value);

  joint4Value = analogRead(joint4PotPin); 
  joint4Value = map(joint4Value, 0, 1023, 0, 180);
  joint4.write(joint4Value);
  
  delay(5);

}

void setup() {
  //Robojax.com multiple servo
  base.attach(basePin); 
  joint1.attach(joint1Pin);   
  joint2.attach(joint2Pin); 
  joint3.attach(joint3Pin);   
  joint4.attach(joint4Pin);  
  clamp.attach(clampPin);
}

void loop() {
 
  Manual();
 
}// loop end