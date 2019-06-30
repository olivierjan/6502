
# ROM Software for the SBC


The EEPROM software is currently divided into BIOS and Monitor.
It Expects a 16k EEPROM starting at $C000 which will contains both

1. BIOS: Entrypoint at startup or Reset, along with I/O Handlers for 6850. The menu currently displays `[B]asic` and `[M]onitor`, but only Monitor is implemented yet.
    
2. Monitor: Jeff Tranter's **JMON** ported to the SBC and **Merlin32**

## Compile 

### Required:
- Merlin32 Assembler: You can get it for Windows, Mac or Linux from [Brutal Deluxe Software](https://www.brutaldeluxe.fr/products/crossdevtools/merlin/index.html). Merlin32 should be in the `PATH` and all the macros from its Library in `/usr/local/includes/merlin32`.
  

- SRecord EEPROM utilities: In order to assemble the final ROM image, you will need [SRecord](http://srecord.sourceforge.net_). For Mac users, you can get it through `brew`. 

- In order to test the ROM without buring it each time, I used [SYMON](https://github.com/sethm/symon), with a small modification to the Multicomp setup to simulate the SBC.

Here the modified code from `src/main/java/com/loomcom/symon/machines/MulticompMachine.java`



    public class MulticompMachine implements Machine {

      private final static Logger logger = Logger.getLogger(MulticompMachine.class.getName());
      
      // Constants used by the simulated system. These define the memory map.
      private static final int BUS_BOTTOM = 0x0000;
      private static final int BUS_TOP    = 0xffff;

      // 40K of RAM from $0000 - $9FFF
      private static final int MEMORY_BASE = 0x0000;
      private static final int MEMORY_SIZE = 0xA000;

      // ACIA at $A000-$BFFF
      private static final int ACIA_BASE = 0xA000;

      // SD controller at $FFD8-$FFDF
      //private static final int SD_BASE = 0xFFD8;

      // 16KB ROM at $C000-$FFFF
      private static final int ROM_BASE = 0xC000;
      private static final int ROM_SIZE = 0x4000;


          // The simulated peripherals
      private final Bus    bus;
      private final Cpu    cpu;
      private final Acia   acia;
      private final Memory ram;
      private       Memory rom;


      public MulticompMachine() throws Exception {
          this.bus = new Bus(BUS_BOTTOM, BUS_TOP);
          this.cpu = new Cpu();
          this.ram = new Memory(MEMORY_BASE, MEMORY_BASE + MEMORY_SIZE - 1, false);
          this.acia = new Acia6850(ACIA_BASE);
          this.acia.setBaudRate(0);

          bus.addCpu(cpu);
          bus.addDevice(ram);
          bus.addDevice(acia, 1);
          //bus.addDevice(new SdController(SD_BASE), 1);
          
          // TODO: Make this configurable, of course.
          File romImage = new File("rom.bin");
          if (romImage.canRead()) {
              logger.info("Loading ROM image from file " + romImage);
              this.rom = Memory.makeROM(ROM_BASE, ROM_BASE + ROM_SIZE - 1, romImage);
          } else {
              logger.info("Default ROM file " + romImage +
                          " not found, loading empty R/W memory image.");
              this.rom = Memory.makeRAM(ROM_BASE, ROM_BASE + ROM_SIZE - 1);
          }

          bus.addDevice(rom);
          
      } 
    }   

## Building the ROM: 
    cd ROM\ Software
    make clean
    make

This will produce 2 files :  
1. `OJROM.bin`: pure binary file to be used with 6502 Simulator (SYMON)
2. `OJROM.hex`: Intel HEX file format, easier to manipulate with EEPROM burner.


Next step: add a BASIC...