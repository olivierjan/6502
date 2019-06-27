*-------------------------------------------------------------------------------
*--
*--   Serial Management routines
*--   Assume a 6850 ACIA
*--
*-------------------------------------------------------------------------------

                  DSK	  Serial.bin
                  ORG   $FF00
                  TYP   $06

TDREBIT           EQU   #%00000010     ; Transmit Data Register Empty bit
RDRFBIT           EQU   #%00000001     ; Receive Data Buffer Full bit
ACIACONFIG        EQU   #%00010100     ; 8bit + 1 stop
CTRLCCODE         EQU   #$03           ; Control-C ASCII Code
ACIA_Base         EQU   $A000          ; ACIA is located at $A000
ACIA_Control      EQU   ACIA_Base + 0  ; Control and Status Register are at the
ACIA_Status       EQU   ACIA_Base + 0  ; same base address
ACIA_Data         EQU   ACIA_Base + 1  ; TXDATA and RXDATA also sharing address



*-------------------------------------------------------------------------------
*-- BIOSCFGACIA Configure ACIA Speed, bits, etc
*-------------------------------------------------------------------------------

BIOSCFGACIA       ENT
                  PHA                 ; Save accumulator
                  LDA   ACIACONFIG    ; Load the configuration bit
                  STA   ACIA_Control  ; Send configuration to ACIA
                  PLA                 ; Restore Accumulator
                  RTS                 ; Job done, return

*-------------------------------------------------------------------------------
*-- BIOSCHOUT handle display of a character on Serial Output
*-- Character must be placed in Accumulator
*-------------------------------------------------------------------------------

BIOSCHOUT         ENT                 ; Global entry point
                  PHA                 ; Save the character on the stack
SERIALOUTBUSY     LDA   ACIA_Status   ; Get Status from ACIA
	                AND	  TDREBIT       ; Mask to keep only TDREBIT
	                CMP	  TDREBIT       ; Check if ACIA is available
	                BNE	  SERIALOUTBUSY ; If ACIA is not ready, check again
	                PLA                 ; Restore Character from Stack
	                STA	  ACIA_Data     ; Actually send the character to ACIA
	                RTS                 ; Job done, return

*-------------------------------------------------------------------------------
*-- BIOSCHGET Retrieve character from ACIA Buffer
*-- Character,if any, will be placed in Accumulator
*-- Carry set if data has been retrieved, cleared if we got nothing
*-------------------------------------------------------------------------------

BIOSCHGET         ENT                 ; Global entry point
                  LDA	  ACIA_Status   ; Get status from ACIA
	                AND	  RDRFBIT       ; Mask to keep only RDRFBIT
	                CMP	  RDRFBIT       ; Is there someting to read ?
	                BNE	  ACIAEMPTY     ; Nothing to read
	                LDA	  ACIA_Data     ; Acrually get data from ACIA
	                SEC		              ; Set Carry if we got somehing
	                RTS                 ; Job done, return
ACIAEMPTY         CLC                 ; We gor norhing, clear Carry
                  RTS                 ; Job done, return

*-------------------------------------------------------------------------------
*-- BIOSCHISCTRLC Get a character and check if it s CTRL-C
*-- Character,if any, will be placed in Accumulator
*-- Carry set if data has been retrieved, cleared if we got nothing
*-------------------------------------------------------------------------------

BIOSCHISCTRLC     ENT                   ; Global entry point
                  JSR   BIOSCHGET       ; Get a charachter
                  BCC   NOTCTRLC        ; Carry clear, we didn't get anything
                  CMP   CTRLCCODE       ; Check the ASCII code
                  BNE   NOTCTRLC        ; We got somehing else
                  SEC                   ; Control-C ! Set Carry and return.
                  RTS                   ; Job done, return
NOTCTRLC          CLC                   ; Clear Carry, we got something else
                  RTS                   ;Job done, return


END
