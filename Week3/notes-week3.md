# Notes week 3

## Task 1

**Files**  sine_wave.ino, Sound_Sensor_Example_NR.ino, Task1.ino <br />

Sometimes, the wavefrom produced from the sound sensor output wasn't perfect.

<img src="squiggly-lines.jpg"
     alt="An unperfect waveform from the sound sensor"
     />

The following helped get the perfect sound waveform using the sound sensor (i.e. no noise and detects speech not just sharp blows):
 - Adjust screw on sound sensor until LED2 just goes out. 
 - Attach the output wire to the correct pin.
 - Wait a minute or so before the sound sensor picks up sound to the right precision. 
 - Ensure there is no background noise when calibrating.

<img src="sound-sensor-waveform.jpg"
     alt="Waveform produced by sound sensor"
     />

**How does LED2 work on the sound sensor?** <br />

**Finding the minimum and maximum output voltages when I talk** <br />

Talking into the microphone, the following plot was found. This means the range of my voice is between 566 and 586. NB: RGB(red, green, blue)
    566 = RGB(0, 255, 0)
    569 = RGB(35, 210, 0)
    572 = RGB(70, 175, 0)
    575 = RGB(105, 140, 0)
    578 = RGB(140, 105, 0)
    581 = RGB(175, 70, 0)
    584 = RGB(210, 35, 0)
    587 = RGB(255, 0, 0)

<img src="my-voice-range.jpg"
     alt="Finding my voice range"
     />

**Implementing the RGB bulb** <br />
Firstly, the bulb was setup using the same layout as last week. Each colour was tested to ensure it was working and the microphone was tested simultanously to checked the were working together. <br />

A range of delay times were tested. Too short a delay time and the change in colour wouldn't be seen. Too long a delay time and the lag would be too great to see the effect. In the end, a comprimise was found. An alternative method is to remove the delays from the LEDs and have no initial setting fot the colour at the start of the loop. <br />

Overall, this task was quite challenging and difficult to measure how successful it was! <br />

**Notes on latency** The issues seen are due to the time delay between the instant the voice is sensed and when the corresponding value sampled is represented by the RGB LED. The affect of latency can become fustrating in human-machine interactions. Futher reading: https://link-springer-com.iclibezp1.cc.ic.ac.uk/chapter/10.1007/978-3-319-20681-3_13 https://en.wikipedia.org/wiki/Latency_(engineering) <br />

**Notes on the ranges I used** Whilst these ranges may be acceptable for my voice, they may not be for another user. To solve this problem, the sensor can be callibrated: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Calibration. This technique was implemented in Task 2.<br />

## Task 2

**Files** Task2.ino <br />

I struggled getting the sound sensor to be sensitive enough to detect me solely speaking. However, it performed well when I blew on it, changing colour appropriately.
