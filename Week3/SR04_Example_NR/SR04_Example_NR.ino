#include <SR04.h>

// Modified for section 3 of Tutorial 3
// Pin numbers for TRIG and ECHO changed to 7 and 6
// Function timepulse() added to obtain raw data from sensor

//www.elegoo.com
//2016.12.08
#include "SR04.h"

#define TRIG_PIN 7
#define ECHO_PIN 6 

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a, b;

void setup() {
   Serial.begin(9600);    //Initialization of Serial Port
   delay(1000);
}

void loop() {
   a=sr04.Distance();     //Return distance in cm
   b=timepulse();         //Return distance in microseconds
   Serial.print(a);
   Serial.print("cm   ");
   Serial.print(b);
   Serial.println("us");
   delay(1000);
}

long timepulse() {
    long duration = 0;
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    duration = pulseIn(ECHO_PIN, HIGH, PULSE_TIMEOUT);
    delay(25);
    return duration;
}
