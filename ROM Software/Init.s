*-------------------------------------------------------------------------------
*--
*--   Initialization Routines
*--   Immediately called at startup, will:
*--												1. Initialize stack
*--												2. Display Startup Message
*--                       3. Jump to Cold or Warm Start based on user input
*-------------------------------------------------------------------------------


									DSK			Init
									ORG 		$FE00
									TYP 		$06

*-------------------------------------------------------------------------------
*-- External routine definition
*-------------------------------------------------------------------------------

BIOSCHOUT					EXT
BIOSCHGET					EXT
BIOSCFGACIA				EXT
BIOSCHISCTRLC			EXT


COLDSTART					EQU			$C000							; Let s see later the Monitor
RESTART 					EQU			$C000             ; And Basic Entry points
STACKTOP 					EQU 		#$F8								; Like a good old Apple //

*-------------------------------------------------------------------------------
*-- Entry point : Reset Vector
*-------------------------------------------------------------------------------

RESET							ENT												; Declare Global
									LDX     STACKTOP					; Load X with new top of stack value
									TXS												; Set the stack pointer

									JSR			BIOSCFGACIA				; Configure ACIA

									LDY			#0								; Initialize counter
]LOOP							LDA 		STARTUPMESSAGE,Y	; Get character at counter
									BEQ			USERINPUT					; If we're done go get user choice
									JSR			BIOSCHOUT					; else display the character
									INY												; Move to next character
									BNE 		]LOOP

*-------------------------------------------------------------------------------
*-- Get and procrss user choice
*-------------------------------------------------------------------------------

USERINPUT					JSR			BIOSCHGET					; Read user input
									BCC 		USERINPUT					; Retry until we get something
									AND 		#$DF							; Convert to UPPER case
									CMP 		#'W'							; Warm Start ?
									BEQ			WARMSTART 				; Let's go for WARM STAFT
									CMP 		#'C'							; Cold Start ?
									BNE 		RESET 						; Something else ? Restart all...
									JMP 		COLDSTART         ; Let's go !
WARMSTART 				JMP 		RESTART 					; Let's go...Warmer

STARTUPMESSAGE		ASC 		0C,'OJ',27,'s SBC V0.1',0D,0A,'Cold [C] or warm [W] start?',0D,0A,00
