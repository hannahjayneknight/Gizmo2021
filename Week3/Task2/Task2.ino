// Lighting the RGB using sound.
// Hannah Knight
// 02/02/2021


// For the sound sensor
int  sensorAnalogPin = A0;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
int  sensorDigitalPin = 12;   // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor
int  digitalValue;            // Define variable to store the digital value coming from the Sound Sensor
int  Led13 = 13;              // Define LED port; this is the LED built in to the Arduino (labled L)
                              // When D0 from the Sound Sensor (connnected to pin 12 on the
                              // Arduino) sends High (voltage present), L will light up. In practice, you
                              // should see LED13 on the Arduino blink when LED2 on the Sensor is 100% lit.

// For the RGB
#define RED 3
#define GREEN 5
#define BLUE 7
int redValue;
int greenValue;
int blueValue;

// For the calibrator
int sensorValue = 0;         // the sensor value
int sensorMin = 500;        // minimum sensor value
int sensorMax = 700;           // maximum sensor value
/*
 * These may seem backwards. Initially, you set the minimum high and read for anything lower than that, saving 
 * it as the new minimum.
 */

                              

void setup()
{
  // For the sound sensor
  Serial.begin(9600);               // The IDE settings for Serial Monitor/Plotter (preferred) must match this speed
  pinMode(sensorDigitalPin,INPUT);  // Define pin 3 as an input port, to accept digital input
  pinMode(Led13,OUTPUT);            // Define LED13 as an output port, to indicate digital trigger reached

  // For the RGB
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

  // For the callibrator
  // calibrate during the first 7 seconds
  while (millis() < 7000) {
    sensorValue = analogRead(sensorAnalogPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  // signal the end of the calibration period
  digitalWrite(13, LOW);
  }
}

void loop(){

  
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A0 assigned to digitalValue 
  digitalValue=digitalRead(sensorDigitalPin); // Read the value of the digital interface 12 assigned to digitalValue -> goes between 1 and 0 (high and low)
  //Serial.println(analogValue); // Send the analog value to the serial transmit interface

  // calibrate
  // apply the calibration to the sensor reading
  sensorValue = map(analogValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  //sensorValue = constrain(analogValue, 0, 255);
  Serial.println(sensorValue);

  if ( -1 < sensorValue < 266) {
    redValue = sensorValue;
    greenValue = 255 - sensorValue;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
  }


  if(digitalValue==HIGH)      // When the Sound Sensor sends signals, via voltage present, light LED13 (L)
  {
    digitalWrite(Led13,HIGH);
 
  }
  else
  {
    digitalWrite(Led13,LOW);
  }
  
  delay(50);                  // Slight pause so that we don't overwhelm the serial interface
}
