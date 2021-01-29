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

int int_customKey = 0;                // Variable to get the integer value of the pressed number
int in_pass = 0;                      // The current speed being introduced
int power[4] = {1000, 100, 10, 1};    // Array to get the result of 10^(2-i) when computing the integer value of the password being introduced
/************************/
  
void setup(){
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey(); // the key that was pressed
  analogWrite(ENABLE, int_pass); // sets initial speed of fan
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRB,LOW);

  if (customKey){                               // when a key is pressed
    int_customKey = customKey - '0';            // Obtaining the integer value of the pressed button. ASCII code of the pressed button minus ASCII code of character '0'.
    in_pass = in_pass + int_customKey*power[i]; // Computing the integer value of the password being introduced
    Serial.print(in_pass);                      // Sending inputed key to the serial monitor
  }



  if (customKey == '#') {                 // # enters the speed of the fan

    Serial.println();
    
    if ( 0 < isdigit(customKey)< 255) {   // checks if the entered phrase is an int between 0 and 255
      
      Serial.println("Fan speed has been set");
      analogWrite(ENABLE, int_pass); // sets new speed of fan
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      in_pass = 0;                                // Resetting the value of the speed introduced
      
    }
    else {
      
      Serial.println("Please type in a speed between 0 and 255");
      in_pass = 0;                                // Resetting the value of the speed introduced
      
    }
    
  }
