# Notes week 4 - Dealing with a concurrent physical world

## Task 1 - Reacting to changes in orientation

**Files** Ball_Switch.ino, Task1.ino, Task1-attempt2.ino<br />

Firstly, a simple circuit was set-up to try using the tilt sensor. This all ran smoothly. <br />

Setup (not tilted so the LED is on):

<img src="flat.jpg" alt="Setup of tilt sensor with LED on."/>

In a tilted position (LED is off): 

<img src="tilted.jpg" alt="Tilt sensor in tilted position with LED off."/>

Then, a LED was added to the circuit to see the effects of code order on when/if the LED lit up. The LED was coded to be on for 5 seconds, followed by being off for 5 seconds and repeat. This code was trialled (1) before the code for the tilt sensor and (2) after the code for the tilt sensor. <br />

The results were the same for both scenarios. <br />

The red LED blinked constantly as desired, however, the led on the board which indicates whether it is tilted or not responded but not until long after the change in position had happened. This is probably due to te fact that during the delay set for the red LED, the code is not "listening" for changes in position of the tilt sensor. <br />

The solution has been based on the following article: https://arduino.stackexchange.com/questions/37684/can-i-make-multiple-void-loops-with-arduino-uno <br />

Here, different functions are made both for the red LED and the tilt sensor. The tilt sensor function does exactly the same as it did before and the red LED function no longer uses ```delay()``` methods. Instead, each time the led function is called it checks for how much time has passed since the previous time it was called. The result can be seen in the _Task1-attempt2.ino_ file. <br />

**Video of tilt sensor working on its own:** <br />

**Video of tilt sensor and LED working together:** <br />

## Task 2 - Controlling a stepper motor

**Files** Ball_Switch.ino, Task1.ino, Task1-attempt2.ino<br />

**About the stepper motor:** 
- The sequence of the applied pulses is directly related to the direction of the motor shaft's rotation.
- The speed of the motor shafts rotation is directly related to the frequency of the input pulses. 
- The length of rotation is directly related to the number of input pulses.

<br />

At first, when I followed the set-up outlined in the lesson, my stepper motor did not turn on.

## Task 3 - Attending events when they happen

**Files** Interrupts.ino <br />

When we first combined the red LED with the tilt sensor, the system didn't work the way we wanted to because of _polling_. This is where the computer waits for an external device to check for its readiness or state and does nothing until this device is ready. <br />

In this exercise, we use _interrupts_ which are signals sent from a device or from software to the operating system. The interrupt signal causes the operating system to temporarily stop what it is doing and ‘service’ the interrupt. This allows the system to run specific pieces of code called _Interrupt Service Routines (or ISRs)_. <br />

The Arduino function ```attachInterrupt()``` allows us to do this easily. 

**Breakdown of _Interrupts.ino_ :** In the loop() of _Interrupts.ino_, you have the redLED blinking. The tilt sensor is only defined in setup() where the interrupt is defined which links to the builtin() function to define what to do depending on the signal from the tilt sensor. The builtin() function is the interrupt handler (aka ISR) which means it tells the computer what to do when the device raises an interrupt. <br />

When we define the interrupt in setup(), we tell the computer that whenever the state of the tilt sensor changes it needs to perform the builtin() function (which is the ISR).
