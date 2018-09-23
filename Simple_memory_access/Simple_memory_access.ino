/*
Bus Access system
Access 65C02 address and databus on 24 Teensy Pins
Start simulate some memory for 65c02 to Read/Write.
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
int resetPin=33;

// Declare global variables
volatile byte addressL, addressL_prev, addressH, addressH_prev, data;
volatile uint8_t rw,currentClock;
volatile uint32_t clockCount;

// memory of 64kb
byte mem[256][256];


void setup() {

  // Start the serial port

  Serial.begin(0);

  // Set all pins to LOW with a PULLDOWN.

  for (int i=0;i<8;i++) {
    pinMode(dataPins[i],OUTPUT);
    pinMode(addressLPins[i],INPUT_PULLDOWN);
    pinMode(addressHPins[i],INPUT_PULLDOWN);
  }


  pinMode(rwPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(resetPin, OUTPUT);


  // Initialize some variables

    addressL=0x0;
    addressL_prev=0x0;
    addressH=0x0;
    addressH_prev=0x0;
    currentClock=0;
    rw=1;
    clockCount=0;

    // Bring the RESET LOW to get the 6502 in a reset state
    digitalWrite(resetPin,LOW);

    // Initialize memory to 0xEA (NOP)
    memset(mem,0xEA,sizeof(mem));

}


void loop(){

// If we have waited long enough for 6502 to init, stop reseting.

  if(clockCount == 8) {
    digitalWrite(resetPin, HIGH);
  }
  // Bring Clock LOW
  GPIOA_PDOR &=0x0000;
  //digitalWrite(clockPin,LOW);


  if (!rw) {
    // Configure pins for Input.
    GPIOD_PDDR=0x00;

    // Read data from Address Bus into memory
    // Address has been given in the last cycle and stored in addressH_prev and addressL_prev

    mem[addressH_prev][addressL_prev]=GPIOD_PDIR & 0xFF;
  } else {
    //Configure pins for Output
    GPIOD_PDDR=0xFF;

    // Write data from memory to Address Bus
    // Address has been given in the last cycle and stored in addressH_prev and addressL_prev
    GPIOD_PDOR= mem[addressH_prev][addressL_prev];
  }


  // Wait a bit
  delay(500);

  // Bring Clock HIGH
  GPIOA_PDOR |=1<<13;


  // Read the Address Bus LSB
  addressL = GPIOC_PDIR;

  // Read the Address Bus MSB
  // Get the first Nibble
  addressH = GPIOB_PDIR;

  // Get the second Nibble
  // Shift the register right by 12 bits to get bits 16,17,18 and 19 in position
  // 4,5,6 and 7.
  // Mask bits 0,1,2,3 and add to addressH.
  addressH |= (GPIOB_PDIR >> 12) & 0xF0;

  // Does the 65C02 wants to Read or Write the data there ?
  // rw=(GPIOA_PDIR>>11)&0x1;
   rw=(GPIOA_PDIR>>12)&0x1;
   if (rw){
     Serial.print("65c02 wants to READ\n");
   } else {
     Serial.print("65c02 wants to WRITE\n");
   }

  if (addressL != addressL_prev || addressH != addressH_prev){
    Serial.print("Address MSB, LSB: ");
    Serial.print(addressH,HEX);
    Serial.print(" ");
    Serial.print(addressL,HEX);
    Serial.print("\n");
    Serial.print("Clock Counter: ");
    Serial.print(clockCount);
    Serial.print("\n");
  }

  if (addressH == 0xEA && addressH_prev == 0xFF && clockCount > 1) {
    Serial.print("Rollover \n");
    clockCount=0;
  }
  if (addressL == 0xEA && addressL_prev != 0xE9 && clockCount > 1) {
    Serial.print("Reset detected !!!! \n");
    clockCount=0;
  }
  addressL_prev=addressL;
  addressH_prev=addressH;
  clockCount++;
  rw=0x1;

}
