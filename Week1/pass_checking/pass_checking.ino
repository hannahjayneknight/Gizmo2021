// Code modified for the password-checking functionality discussed in Tutorial 1
// N. Rojas

//www.elegoo.com
//2016.12.9

/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>

const byte pinGREEN = 21;
const byte pinRED = 14;

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
// Variables for the password-checking functionality
const int pass = 1534;           // The password
int i = 0;                      // Variable to know the position in the sequence of a pressed number
int int_customKey = 0;          // Variable to get the integer value of the pressed number
int in_pass = 0;                // The current password being introduced
int power[4] = {1000, 100, 10, 1};    // Array to get the result of 10^(2-i) when computing the integer value of the password being introduced
/************************/
  
void setup(){
  Serial.begin(9600);
  // initialize digital pin 14 and 21 as outputs.
  pinMode(pinGREEN, OUTPUT);
  pinMode(pinRED, OUTPUT);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    if (i < 4){                                   // If i < 3, more numbers to complete the password are needed
      int_customKey = customKey - '0';            // Obtaining the integer value of the pressed button. ASCII code of the pressed button minus ASCII code of character '0'.
      in_pass = in_pass + int_customKey*power[i]; // Computing the integer value of the password being introduced
      i = i+1;                                    // A button has been pressed, so the position in the sequence for the next number is updated
      Serial.print('*');                          // Sending character '*' for the serial monitor
    }
  if (i >= 4){                                    // If i >= 3, a full password has been introduced. Time to check!
     Serial.println();
     if (in_pass == pass){                        // Is the introduced password equal to the password (pass)?
      Serial.println("Password is correct");      // The password introduced is correct. Sending info to the serial monitor
      digitalWrite(pinGREEN, HIGH);               // turn the green LED on (HIGH is the voltage level)
      delay(1000);                                // wait for a second
      digitalWrite(pinGREEN, LOW);                // turn the green LED off by making the voltage LOW
      delay(1000);                                // wait for a second
      in_pass = 0;                                // Resetting the value of the password introduced
      i = 0;                                      // Resetting the sequence counter
      }
      else{
      Serial.println("Password is not correct");  // The password introduced is not correct. Sending info to the serial monitor
      digitalWrite(pinRED, HIGH);                 // turn the red LED on (HIGH is the voltage level)
      delay(1000);                                // wait for a second
      digitalWrite(pinRED, LOW);                  // turn the red LED off by making the voltage LOW
      delay(1000);                                // wait for a second
      in_pass = 0;                                // Resetting the value of the password introduced
      i = 0;                                      // Resetting the sequence counter   
      }
    }
  }
}
