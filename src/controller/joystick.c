/*

  Joystick module that could be used to adjust Serial 7 Segment display
  or manipulate microservos
  
  Joystick consists of:
  
  GND --->  0v
  VCC --->  +5v or +15v
  A0  --->  Analog 0
  A1  --->  Analog 1
  SW  --->  Switch button (not included)

*/

// Servo library
#include <Servo.h>

// Two servos
Servo s1;
Servo s2;

// Two directions
int joyX = 0;
int joyY = 1;

// Joystick representation
int value;

// Arduino version of int main(int *argc, char **argv)
void setup(){
  // attaches based on pins on PWM 3-5
  s1.attach(3);
  s2.attach(5);
}

// Arduino version of while(1)
void loop(){
  // reads the joystick value (0-1023 = 2^10)
  value = analogRead(joyX);
  value = map (value, 0, 1023, 0 ,180); // servo value 0-180
  s1.write(value);  // sets servo position based on joystick value;
  
  value = analogRead(joyT);
  value = map (value, 0, 1023, 0 ,180); // servo value 0-180
  s2.write(value);  // sets servo position based on joystick value;
}

