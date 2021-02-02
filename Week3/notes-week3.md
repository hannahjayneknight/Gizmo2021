# Notes week 3

## Task 1

Sometimes, the wavefrom produced from the sound sensor output wasn't perfect.

<img src="squiggly-lines.jpg"
     alt="An unperfect waveform from the sound sensor"
     />

The following helped get the perfect sound waveform using the sound sensor (i.e. no noise and detects speech not just sharp blows):
	- Adjust screw on sound sensor until LED2 just goes out. 
	- Attach the output wire to the correct pin.
Ensure there is no background noise when calibrating.

<img src="sound-sensor-waveform.jpg"
     alt="Waveform produced by sound sensor"
     />

**How does LED2 work on the sound sensor?** <br />

**Finding the minimum and maximum output voltages when I talk** <br />

Talking into the microphone, the following plot was found. This means the range of my voice is between 566 and 586.

<img src="my-voice-range.jpg"
     alt="Finding my voice range"
     />