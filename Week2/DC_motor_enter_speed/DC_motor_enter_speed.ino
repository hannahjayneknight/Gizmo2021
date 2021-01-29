// Controlling the speed of the fan using the membrane keypad.
// Hannah Knight

#include <Keypad.h>


#define ENABLE 12
#define DIRA 10
#define DIRB 11

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the two-dimensional array on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

/************************/
int i = 0;                      // Variable to know the position in the sequence of a pressed number
int int_customKey = 0;                // Variable to get the integer value of the pressed number
int in_speed = 0;                      // The current speed being introduced
int power[3] = {100, 10, 1};    // Array to get the result of 10^(2-i) when computing the integer value of the password being introduced


/************************/
  
void setup(){
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
  Serial.println("Please type the fan speed as a 3 digit number (using leading zeroes where appropriate)"); 
}
  
void loop(){
  char customKey = customKeypad.getKey(); // the key that was pressed

  if (customKey && (customKey != '#') ){        // when a key is pressed that is not the enter key
    
    int_customKey = customKey - '0';            // Obtaining the integer value of the pressed button. ASCII code of the pressed button minus ASCII code of character '0'.
    in_speed = in_speed + int_customKey*power[i]; // Computing the integer value of the password being introduced
    i = i+1;
    Serial.println(in_speed);
  
  }

  if (customKey == '#') {                       // when enter key is pressed

    if ( 0 < in_speed < 255) {
      Serial.println();
      Serial.print("Fan speed has been set to ");
      Serial.println(in_speed);
      analogWrite(ENABLE, in_speed); //enable on
      digitalWrite(DIRA,HIGH); //one way
      digitalWrite(DIRB,LOW);
      delay(3000);
      in_speed = 0 ;
      i = 0;
            
    }
    else {
      Serial.println();
      Serial.println("Please type in a speed between 0 and 255");
      in_speed = 0;
      i = 0;
    }

      
  }

}
