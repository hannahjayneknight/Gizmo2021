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
  led();
  tilt();
}

void led ()
{
  static unsigned long lastTime = 0;
  const long interval = 3000;
  static bool state = 0;

  unsigned long now = millis();

  if ( now - lastTime > interval && state == 0) {
    state = 1;
    lastTime = now;
    digitalWrite(redLED, HIGH);
  }

  if ( now - lastTime > interval && state == 1) {
    state = 0;
    lastTime = now;
    digitalWrite(redLED, LOW);
  }
}

void tilt ()
{
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
