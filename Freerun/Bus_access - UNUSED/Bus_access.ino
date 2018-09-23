/*
Bus Access system
Access 65C02 address and databus on 24 Teensy Pins

*/

#include "wiring.h"

// Declare the Pins to use

// Data Bus
byte dataPins[] = {2,14,7,8,6,20,21,5};

// Address Bus MSB
byte addressHPins [] = {16,17,19,18,0,1,29,30};

// Address Bus LSB
byte addressLPins[]={15,22,23,9,10,13,11,12};

// R/W' and Clock
int rwPin=3;
int clockPin=4;

// Declare global variables
volatile byte addressL, addressL_prev, addressH, addressH_prev, data;
volatile uint8_t rw,currentClock;
volatile uint32_t clockCount;


void setup() {

  // Start the serial port

  Serial.begin(0);

  // Set all pins to LOW with a PULLDOWN.

  for (int i=0;i<8;i++) {
    pinMode(dataPins[i],INPUT_PULLDOWN);
    pinMode(addressLPins[i],INPUT_PULLDOWN);
    pinMode(addressHPins[i],INPUT_PULLDOWN);
  }


  pinMode(rwPin, INPUT_PULLDOWN);
  pinMode(clockPin, INPUT_PULLDOWN);


  // Initialize some variables

    addressL=B00000000;
    addressH=B00000000;
    currentClock=0;
    rw=1;
    clockCount=0;

  // attach Interrupts to the Clock

  attachInterrupt(clockPin, phase1, FALLING);
  attachInterrupt(clockPin, phase2, RISING);

}

// RW' and Address are Valid
void phase1(){

  // Read the Address Bus LSB
  addressL = GPIOC_PDIR & 0xFF;

  // Read the Address Bus MSB
  // Get the first Nibble
  addressH = GPIOB_PDIR & 0xF;

  // Get the second Nibble
  // Shift the register right by 12 bits to get bits 16,17,18 and 19 in position
  // 4,5,6 and 7.
  // Mask bits 0,1,2,3 and add to addressH.
  addressH |= (GPIOB_PDIR >> 12) & 0xF0;

  // Does the 65C02 wants to Read or Write the data there ?
  rw=(GPIOA_PDIR>>11)&0x1;
}

// Data from 65C02 is on the Data Bus
// Data can be written to Data Bus

void phase2() {

// increment the clock counter

  clockCount++;
  // Read Data Bus if CPU wants to WRITE
  // for the time being, let's write NOP in case 65C02 wants to READ.

  if (rw) {
    data=GPIOD_PDIR & 0xFF;
  } else {
    GPIOD_PDOR= 0xEA;
  }



}


void loop(){

}
