## 6502
Simple code to get a running 65C02.
Starting with a Teensy 3.6 to emulate the rest of the hardware, the target is to remove the Teensy steps by steps.

1. *Freerun*:  A simple test of the 65C02 by sending NOP and checking it goes through it's address range.

2. *Simple_memory_access*: Emulate the hardware around the 6502.

3. *MS Basic (OSI)*: Contains the MS Basic assembly code from Grant Searle (http://searle.hostei.com/grant/6502/Simple6502.html).

4. *Serial_Interface.X*: Work in progress to get a PIC working as a simple ACIA for the 6502.

5. *SBC* : Start adding real ICs instead of Teensy. Now work with RAM and ROM chips.

6. *ROM Software*: Contains EEPROM content and code to build it. So far, a simple boot menu, I/O handlers and a Monitor (__JMON__).

Olivier
