// the setup function runs once when you press reset or power the board

#define READPORT PORTB
#define DATAPORT PORTA

#define NIBBLE_H PORT_PA19 | PORT_PA18 | PORT_PA17 | PORT_PA16
#define NIBBLE_L PORT_PA11 | PORT_PA10 | PORT_PA09 | PORT_PA08

#define RW PORT_PB02
#define CLOCK PORT_PB08
#define ADDRESS PORT_PB09
#define ENABLE PORT_PB11

volatile uint32_t ACIAStatus=2;
volatile uint32_t SendBuffer=0x00;
volatile uint32_t ReceiveBuffer=0x00;
volatile uint32_t DataBuffer=0x00;
volatile uint32_t StatusBuffer=0x00;


void setup() {

  // Startup Serial (USB)
  Serial.begin(9600);

  //Setup the ports

  PORT->Group[READPORT].DIRSET.reg = 0x00;
  PORT->Group[DATAPORT].DIRSET.reg = 0x00;
}

// the loop function runs over and over again forever
void loop() {

  // Read the CLOCK, ENABLE, RW and ADDRESS to see what is expected from us.
  StatusBuffer=PORT->Group[READPORT].IN.reg;
  DataBuffer=PORT->Group[READPORT].IN.reg;

  // If we are requested to work
  if (StatusBuffer & (CLOCK | ENABLE)) {

      // Are we expected to send something ?
      if (StatusBuffer & RW){
        // Change PORT direction
        PORT->Group[DATAPORT].DIRSET.reg= NIBBLE_H | NIBBLE_L;

        // Send what we have to send and change status

        if (StatusBuffer & ADDRESS){
          PORT->Group[DATAPORT].OUTSET.reg = ACIAStatus;
        } else {
          PORT->Group[DATAPORT].OUTSET.reg = SendBuffer;
        }

        // Change back PORT direction.
        PORT->Group[DATAPORT].DIRSET.reg=0x00;

      } else {

        // Store it for later processing
        ReceiveBuffer=DataBuffer;
      }

  } else {

    // If we are not requested to do anything

      // Check if we have something to print or to write
      ACIAStatus =(Serial.available()>0) ? 3 : 2;

      // Serial Buffer contains something
      if (ACIAStatus == 3) {
        // Read Serial Port into the Buffer

        SendBuffer=(uint32_t) Serial.read();
      }

      // Shift ACIAStatus to make it sendable through Teensy ports.
      // We only need to shift the Low nibble as 2 or 3 won't require
      // more than 4 bits anyway.

      ACIAStatus=(ACIAStatus<<8);


      // If we have received something, let's print it.

      if (ReceiveBuffer){

        // Clean the 32-bit buffer to make it 8-bit compatible.
        // A bit of cleaning.
        ReceiveBuffer &= ((NIBBLE_H)|(NIBBLE_L));

        // Shift it to get everything in porsition
        ReceiveBuffer = ((ReceiveBuffer >> 12)&0xF0)|((ReceiveBuffer >> 8)&0x0F);

        // Now we can print the content of the buffer
        Serial.print((char)ReceiveBuffer&0xFF);

        // Cleanup the buffer
        ReceiveBuffer=0x0;
      }
  }
}
