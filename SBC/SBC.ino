/*
Bus Access system
Access 65C02 address and databus on 24 Teensy Pins
Start simulate some memory for 65c02 to Read/Write.
*/

#include "msbasicrom.h"
#include "SBC.h"

// Declare the Pins to use


byte dataPins[] = {2,14,7,8,6,20,21,5};         // Data Bus
byte addressHPins [] = {16,17,19,18,0,1,29,30}; // Address Bus High byte
byte addressLPins[]={15,22,23,9,10,13,11,12};   // Address Bus Low byte
uint8_t chipEnable;                             // RAM, ROM or Serial to access

// Declare global variables
// Must be volatile to avoid any compiler optimization

volatile byte addressL,addressH,data;
volatile uint16_t i;
volatile boolean rw;
volatile byte ACIAStatus;
volatile uint16_t address;

// Redefine yield() as the default one is useless and waste time.
void yield(){}

void setup() {

  Serial.begin(0);                // Start the serial port

  // Set all pins to their initial state.
  for (int i=0;i<8;i++) {
    pinMode(dataPins[i],INPUT);               //Ensure we're not writing to the Bus
    pinMode(addressLPins[i],INPUT_PULLDOWN);
    pinMode(addressHPins[i],INPUT_PULLDOWN);
  }

  pinMode(RWPIN, INPUT);
  pinMode(CLOCKPIN, OUTPUT);
  pinMode(RESETPIN, OUTPUT);


  // Initialize some variables
  addressL=0x0;
  addressH=0x0;
  chipEnable=0x0;
  rw=true;

  digitalWrite(RESETPIN,LOW);     // Bring the RESET LOW to get the 6502
                                  // in a reset state
  delay(2000);                    // Keep RESET for 2 second
                                  // in order for Serial to be ready
  digitalWrite(RESETPIN,HIGH);    // Release RESET and start working
}


void loop(){

  GPIOA_PDOR &=0x0000;              // Bring Clock LOW to start Phase 1
  for (i=0; i< WAITCYCLE; i++){}    // Keep Phase 1 LOW
  GPIOA_PDOR |=1<<13;               // Bring Clock HIGH to start Phase 2


  addressL = GPIOC_PDIR;                  // Read the Address Bus Low byte
  addressH = GPIOB_PDIR;                  // Read the Address Bus High byte
  addressH |= (GPIOB_PDIR >> 12) & 0xF0;  // Shift the register right by 12 bits
                                          // to get bits 16,17,18 and 19
                                          // in position 4,5,6 and 7.
                                          // Mask bits 0,1,2,3 and
                                          // add to addressH.

  address = ((uint16_t)addressH << 8)| addressL; // Build the complete address
  chipEnable = addressH >> 5;               // Detect which chip should be selected
  rw=(GPIOA_PDIR>>12)&0x1;                  // Check if it's a Write Cycle
                                            // or Read Cycle
  GPIOD_PDDR=(rw) ? GPIOOUTPUT : GPIOINPUT; // Configure PIN direction.

  switch (chipEnable) {
    case ACIAENABLE:          // Serial Chip Selected
      if (rw) {               // 65C02 wants to read data
        // Two options: Check if there is data to read or Read data.
        GPIOD_PDOR=(address == SERIALADDRESS) ? ((Serial.available()>0) ? 3 : 2) : Serial.read() ;
      } else {
        if (address== SERIALADDRESS + 1) {      // Sending something to display ?
          Serial.write((char)GPIOD_PDIR&0xFF);  // Sends the data to Serial Interface.
        }
        // We simply ignore the case where we receive config byte for ACIA.
      }
      break;

    case ROMENABLEC000:         // ROM is selected
    case ROMENABLEE000:         //
      address-=ROMADDRESS;      //Change address to map to ROM address range
      GPIOD_PDOR= rom[address]; // Write data from ROM to Address Bus
      break;

    default:
      break;
  }
  GPIOD_PDDR=GPIOINPUT;           // Switch back GPIO to Input
}
