// the setup function runs once when you press reset or power the board

#define TESTEDPIN PORT_PB11
#define TESTEDPORT PORTB

void setup() {
  // initialize digital pin 13 as an output.
  // pinMode(13, OUTPUT);
  Serial.begin(9600);
  PORT->Group[TESTEDPORT].DIRSET.reg = TESTEDPIN;
  PORT->Group[TESTEDPORT].OUTSET.reg = TESTEDPIN;
}

// the loop function runs over and over again forever
void loop() {
   Serial.print("Hello\n");
  // digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  // delay(100);              // wait for a second
  // digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  PORT->Group[TESTEDPORT].OUTTGL.reg = TESTEDPIN;
  delay(100);              // wait for a second
}
