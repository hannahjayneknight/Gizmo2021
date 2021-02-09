//Part 3 Tutorial 4

const int ledPin = 13;    //Built-in LED
const int redLED = 3;
const int tiltSensor = 2; //Tilt sensor

void setup()
{ 
  pinMode(ledPin,OUTPUT);          //Initialize the ledPin as an output
  pinMode(tiltSensor,INPUT);       //Initialize tilt sensor pin as an input
  digitalWrite(tiltSensor, HIGH);
  pinMode(redLED,OUTPUT);          //Initialize the redLED as an output
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

void loop() 
{ 
  digitalWrite(redLED,HIGH);
  delay(5000);
  digitalWrite(redLED,LOW);
  delay(5000);
}

void builtin() //ISR
{
  if(HIGH == digitalRead(tiltSensor))
  {
    digitalWrite(ledPin,LOW);         //turn the led off
  }
  else
  {
    digitalWrite(ledPin,HIGH);        //turn the led on 
  }

}
