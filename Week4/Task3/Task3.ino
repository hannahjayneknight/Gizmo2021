#include <Stepper.h>

//www.elegoo.com
//2018.10.25

/*
  Stepper Motor Control - one revolution

  This program drives a unipolar or bipolar stepper motor.
  The motor is attached to digital pins 8 - 11 of the Arduino.

  The motor should revolve one revolution in one direction, then
  one revolution in the other direction.

  There are 2048 steps per revolution. 

*/

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
int rolePerMinute = 15;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

const int ledPin = 13;    //Built-in LED
const int tiltSensor = 2; //Tilt sensor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // set up stepper
  myStepper.setSpeed(rolePerMinute);
  // initialize the serial port:
  Serial.begin(9600);
  Serial.println(rolePerMinute);

  // set up tilt sensor
  pinMode(ledPin,OUTPUT);          //Initialize the ledPin as an output
  pinMode(tiltSensor,INPUT);       //Initialize tilt sensor pin as an input
  digitalWrite(tiltSensor, HIGH);
  attachInterrupt(digitalPinToInterrupt(tiltSensor), builtin, CHANGE); //Definition of interrupt

  if(HIGH == digitalRead(tiltSensor))
  {
    digitalWrite(ledPin,LOW);//turn the led off
  }
  else
  {
    digitalWrite(ledPin,HIGH);//turn the led on 
  }  
}

void loop() {  
  // step one revolution in one direction:
  myStepper.step(stepsPerRevolution);
  delay(500);
  Serial.println(rolePerMinute);
  if ( rolePerMinute != 15)
  {
    rolePerMinute += 5;
  }
  else
  {
    rolePerMinute = 5;
  }

}

void builtin() //ISR
{
  if(HIGH == digitalRead(tiltSensor))
  {
    digitalWrite(ledPin,LOW);         //turn the led off
    myStepper.setSpeed(0);
  }
  else
  {
    digitalWrite(ledPin,HIGH);        //turn the led on 
    //myStepper.setSpeed(rolePerMinute);            // add this in if you want the stepper motor to turn back on when the tilt sensor returns to original position
  }

}
