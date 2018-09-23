
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// Pin 2 has the LED on ESP8266
// give it a name:

#define led 2
#define clockdelay 100

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  Serial.begin(115200);
  Serial.print("Configuring pin ");
  Serial.print(led);
  Serial.print("\n");
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  //Serial.print("Going High on pin ");
  //Serial.print(led);
  //Serial.print("\n");
  delay(clockdelay);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  //Serial.print("Going Low");
  //Serial.print(led);
  //Serial.print("\n");
  delay(clockdelay);               // wait for a second
}
