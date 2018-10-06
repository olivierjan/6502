/*
Bus Access system
Access 65C02 address and databus on 24 Teensy Pins
Start simulate some memory for 65c02 to Read/Write.
*/

#include "wiring.h"
#include "msbasicrom.h"

#define waitCycle 2

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
volatile uint8_t rw,currentClock,i;
volatile uint32_t clockCount;
volatile uint16_t fullAddress;
volatile uint16_t address;
volatile byte ACIAStatus;

// memory of 64kb
byte mem[0x9FF];


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
  memset(mem,0x00,sizeof(mem));

  delayMicroseconds(500);

  // Release RESET and start working
  digitalWrite(resetPin,HIGH);

}


void loop(){

  // Bring Clock LOW to start Phase 1
  GPIOA_PDOR &=0x0000;

  delayMicroseconds (waitCycle);
  // Bring Clock HIGH to start Phase 2
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
  rw=(GPIOA_PDIR>>12)&0x1;

  //delayMicroseconds(waitCycle);


  //delayMicroseconds(waitCycle);

  // Aggregate LSB and MSB to get the full 16bit address.
  address = ((uint16_t)addressH << 8)| addressL;

  // If 65C02 wants to Read
  if (rw){

    // If we have data waiting on the serial port, change the ACIA Status
    ACIAStatus =(Serial.available()>0) ? 3 : 2;

    //Configure pins for Output
    GPIOD_PDDR=0xFF;

      // Address is in ROM ?
      if ( address >= ROMADDRESS){

        //Change address to map to ROM address range
        address-=ROMADDRESS;

        // Write data from ROM to Address Bus
        GPIOD_PDOR= rom[address];

        // If address correspond to serial port memory address range ($A000-$A001)
          } else if (address >= SERIALADDRESS){
          if (address == SERIALADDRESS) {
            // Send ACIA Status
            GPIOD_PDOR=ACIAStatus;
          } else {

            // Send the character from serial
            GPIOD_PDOR=Serial.read();
          }

          // Not ROM or Serial, we're looking for data in RAM
      } else {
        // Output the byte located at address
        GPIOD_PDOR= mem[address];
      }
    // if 65C02 wants to write
  } else {

    // Switch GPIO to Input
    GPIOD_PDDR=0x00;

    // Writing to ROM !!!!!
    if ( address >= ROMADDRESS){
      // Trying to write to ROM - not good !!!
      Serial.print("!!! TRYING TO WRITE TO ROM !!!!\n");

      // Writing to Serial address range
    } else if (address >= SERIALADDRESS){

          // Read data from Address Bus and display directly if sent on data line(SERIALADDRESS + 1).
          if (address== SERIALADDRESS + 1) {
            Serial.write((char)GPIOD_PDIR&0xFF);
          }

        // Writing to RAM
    } else {
      mem[address]=GPIOD_PDIR;
    }
  }


  // Wait a bit
//  delayMicroseconds(waitCycle);

  // Next cycle
  for (i=0; i< 8; i++){}
  clockCount++;


}
