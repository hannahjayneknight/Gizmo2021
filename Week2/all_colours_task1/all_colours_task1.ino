// Hannah Jayne Knight
// 29/ 01/ 2021
// A sketch to go through all the possible colours between RGB(255, 0, 0) and RGB(255, 255, 255).

// define pins
#define BLUE 3
#define GREEN 5
#define RED 7

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

  Serial.begin(9600); // sets the data rate in bits per second (baud) for serial transmission
}

// define variables
int redValue;
int greenValue;
int blueValue;

// main loop
void loop()
{
#define delayTime 200 // fading time in ms

  redValue = 255;
  greenValue = 0;
  blueValue = 0;

  Serial.print ("Red is   ");
  Serial.println (redValue);
  Serial.print ("Green is   ");
  Serial.println (greenValue);
  Serial.print ("Blue is   ");
  Serial.println (blueValue);

   for (int i = 0; i < 255; i += 17) // slowly brings red to full
  {
    blueValue = 0;
    greenValue = 0;
    redValue += 17;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
    Serial.print ("Red is   ");
    Serial.println (redValue);
    Serial.print ("Green is   ");
    Serial.println (greenValue);
    Serial.print ("Blue is   ");
    Serial.println (blueValue);

    for (int i = 0; i < 255; i += 17) // slowly brings green to full
    {
      blueValue = 0;
      greenValue += 17;
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
      delay(delayTime);
      Serial.print ("Red is   ");
      Serial.println (redValue);
      Serial.print ("Green is   ");
      Serial.println (greenValue);
      Serial.print ("Blue is   ");
      Serial.println (blueValue);


      for (int i = 0; i < 255; i += 17) // slowly brings blue to full
      {
        blueValue += 17;
        analogWrite(BLUE, blueValue);
        delay(delayTime);
        Serial.print ("Red is   ");
        Serial.println (redValue);
        Serial.print ("Green is   ");
        Serial.println (greenValue);
        Serial.print ("Blue is   ");
        Serial.println (blueValue);
      }
    
    
    }

  }



  Serial.print ("Red is   ");
  Serial.println (redValue);
  Serial.print ("Green is   ");
  Serial.println (greenValue);
  Serial.print ("Blue is   ");
  Serial.println (blueValue);
}
