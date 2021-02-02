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
}

void loop(){

  
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A0 assigned to digitalValue 
  digitalValue=digitalRead(sensorDigitalPin); // Read the value of the digital interface 12 assigned to digitalValue 
  Serial.println(analogValue); // Send the analog value to the serial transmit interface


  if ( 565 < analogValue < 569) {
    redValue = 0;
    greenValue = 255;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
  }

  if ( 568 < analogValue < 572) {
      redValue = 35;
      greenValue = 210;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
  }

  if ( 571 < analogValue < 574) {
      redValue = 70;
      greenValue = 175;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
  }

  if ( 575 < analogValue < 578) {
      redValue = 105;
      greenValue = 140;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      delay(1000);
  }

  if ( 580 < analogValue < 584) {
      redValue = 175;
      greenValue = 70;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
  }

  if ( 583 < analogValue < 587) {
      redValue = 210;
      greenValue = 35;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      delay(1000);
  }

  if ( 586 < analogValue < 590) {
      redValue = 255;
      greenValue = 0;
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
