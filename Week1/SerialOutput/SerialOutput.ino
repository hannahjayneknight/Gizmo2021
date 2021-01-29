/*
 * SerialOutput sketch
 * Print numbers to the serial port
 */

void setup() {
  Serial.begin(9600); // send and receive at 9600 baud (a measure of the number of bits transmitted per sec
  // this is aproximately 1,000 characters per sec
}

int number = 0;

void loop() {
  Serial.print("The number is ");
  Serial.println(number); // print the number (ln creates a new line after)

  delay(500); // delay half second between numbers
  number++; // adds 1 to the variable number
}

// note that whenever you press the Serial Monitor icon in the IDE, it starts counting from scratch
