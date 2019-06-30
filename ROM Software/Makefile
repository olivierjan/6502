##### Build full ROM image

rom: BIOS/BIOS.bin Monitor/Monitor.bin
	srec_cat Monitor/Monitor.bin -Binary BIOS/BIOS.bin -Binary -offset 0x3000  -Output OJROM.bin -Binary --address-length=2 
	srec_cat OJROM.bin -Binary -offset 0xC000  -Output OJROM.hex -Intel --address-length=2 

BIOS/BIOS.bin:
	(cd BIOS ; make)

Monitor/Monitor.bin:
	(cd Monitor ; make)

clean: 
	$(RM) BIOS/*.txt BIOS/*.bin Monitor/*.txt Monitor/*.bin *.bin *.hex

