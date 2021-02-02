// Sending a sine wave to serial monitor/plotter

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 360; i++)
  {
    Serial.println(sin(3*i*DEG_TO_RAD));
  }
}
