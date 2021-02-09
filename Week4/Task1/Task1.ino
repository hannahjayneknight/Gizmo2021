//www.elegoo.com
//2016.12.08

const byte pinLED = 13;
const byte redLED = 12;

void setup()
{ 
  pinMode(pinLED,OUTPUT);//initialize the ledPin as an output
  pinMode(2,INPUT);
  digitalWrite(2, HIGH);

  // RED LED
  pinMode(redLED, OUTPUT);
} 

void loop() 
{ 
  digitalWrite(redLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);                       // wait for 5 seconds
  digitalWrite(redLED, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);                       // wait for 5 seconds
  
  int digitalVal = digitalRead(2); //read pin 2
  
  if(HIGH == digitalVal)
  {
    digitalWrite(pinLED,LOW);//turn the led off
  }
  else
  {
    digitalWrite(pinLED,HIGH);//turn the led on 
  }

}
