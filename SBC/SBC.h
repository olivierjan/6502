/*
Bus Access system
Access 65C02 address and databus on 24 Teensy Pins
Start simulate some memory for 65c02 to Read/Write.
*/


#define WAITCYCLE 5           // How long do we wante Phase 1 to be.


// PIN definitions

#define RWPIN 3               // Read/Write' signal
#define CLOCKPIN 4            // Clock generation
#define RESETPIN 33           // Reset signal
#define ROMADDRESS 0xC000     // Base address of ROM Data
#define SERIALADDRESS 0xA000  // Base address of Serial Device
#define ACIAENABLE 5          // ACIA is used when A15,A13 HIGH and A14 LOW
                              // This gives 0b101(5)
#define ROMENABLEC000 6       // ROM is accessed when A15 and A14 are HIGH
#define ROMENABLEE000 7       // which is 0b110(6) or 0b111(7)
#define GPIOOUTPUT 0xFF       // Value to configure Pins for Output
#define GPIOINPUT 0x00        // Value to configure Pins for Input
