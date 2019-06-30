# Build the BIOS part using Merlin32

BIOS: Init.s Serial.s Vectors.s
	Merlin32 -V /usr/local/includes/merlin32 BIOS.S
	srec_cat Init.bin -Binary Serial.bin -Binary -offset 0x0f00 Vectors.bin -Binary -offset 0x0ffa -Output BIOS.bin -Binary --address-length=2 
	#srec_cat Init.bin -Binary -offset 0xfe00 Serial.bin -Binary -offset 0x0f00 Vectors.bin -Binary -offset 0xfffa -Output BIOS.hex -Intel --address-length=2 


clean: 
	rm *.txt *.bin *.hex *.c