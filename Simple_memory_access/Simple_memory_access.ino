/*
Bus Access system
Access 65C02 address and databus on 24 Teensy Pins
Start simulate some memory for 65c02 to Read/Write.
*/

#include "wiring.h"
#include "msbasicrom.h"

#define waitCycle 10000

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
volatile uint16_t fullAddress;
volatile uint16_t address;

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
  digitalWrite(resetPin,HIGH);

}


void loop(){

  // Bring Clock LOW
  GPIOA_PDOR &=0x0000;

  delayMicroseconds (waitCycle);

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

  delayMicroseconds(waitCycle);

  // Bring Clock HIGH
  GPIOA_PDOR |=1<<13;

  delayMicroseconds(waitCycle);
  address = ((uint16_t)addressH << 8)| addressL;

  //Serial.print(address,HEX);

  // Writing
  if (rw){

    //Serial.print(" R ");

    //Configure pins for Output
    GPIOD_PDDR=0xFF;

      if ( address >= ROMADDRESS){

        //Change address to map to ROM
        address-=ROMADDRESS;

        // Write data from ROM to Address Bus
        GPIOD_PDOR= rom[address];
        //Serial.print(rom[address],HEX);
        //Serial.print("\n");
      } else if (address >= SERIALADDRESS){
          if (address == SERIALADDRESS) {
            GPIOD_PDOR=0x2;
            //Serial.print("02\n");
          } else {
            Serial.print("Reading from bad Serial address!!!\n");
          }
      } else {
        GPIOD_PDOR= mem[address];
        //Serial.print(mem[address],HEX);
        //Serial.print("\n");
      }
  } else {

    //Serial.print(" W ");
    GPIOD_PDDR=0x00;

    if ( address >= ROMADDRESS){
      // Trying to write to ROM - not good !!!
      Serial.print("!!! TRYING TO WRITE TO ROM !!!!\n");
    } else if (address >= SERIALADDRESS){
          // Read data from Address Bus and display directly if sent on data line(SERIALADDRESS + 1).
          if (address== SERIALADDRESS + 1) {
            //Serial.print(GPIOD_PDIR&0xFF,HEX);
            Serial.write((char)GPIOD_PDIR&0xFF);
            //Serial.print("\n");
            //Serial.print(".");
          } else {
            //Serial.print(GPIOD_PDIR&0xFF,HEX);
            //Serial.print("\n");
          }
    } else {
      mem[address]=GPIOD_PDIR;
      //Serial.print(mem[address],HEX);
      //Serial.print("\n");
    }

  }


  // Wait a bit
  delayMicroseconds(waitCycle);

  addressL_prev=addressL;
  addressH_prev=addressH;
  clockCount++;

  //rw=0x1;

}
