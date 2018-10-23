// the setup function runs once when you press reset or power the board

#define TESTEDPIN PORT_PA18 | PORT_PA19 | PORT_PA17
#define READPORT PORTB
#define DATAPORT PORTA

#define NIBBLE_H PORT_PA19 | PORT_PA16 | PORT_PA18 | PORT_PA07
#define NIBBLE_L PORT_PA23 | PORT_PA22 | PORT_PA10 | PORT_PA11

#define RW PORT_PB02
#define CLOCK PORT_PB08
#define ADDRESS PORT_PB09
#define ENABLE PORT_PB011

volatile boolean enable=0;
volatile boolean clock=0;
volatile boolean rw=0;
volatile uint_8 address=0;

void setup() {
  Serial.begin(9600);
  Serial.println(TESTEDPIN,HEX);
  PORT->Group[TESTEDPORT].DIRSET.reg = TESTEDPIN;
  PORT->Group[TESTEDPORT].OUTSET.reg = TESTEDPIN;
}

// the loop function runs over and over again forever
void loop() {

  Serial.println(TESTEDPIN,HEX);
  Serial.println(PORT_PA13, HEX);
  PORT->Group[TESTEDPORT].OUTTGL.reg = TESTEDPIN;
  delay(100);              // wait for a second
}
