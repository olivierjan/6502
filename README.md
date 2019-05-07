# 6502
Simple code to get a running 65C02.
Starting with a Teensy 3.6 to emulate the rest of the hardware, the target is to remove the Teensy steps by steps.

1. *Freerun* is a simple test of the 65C02 by sending NOP and checking it goes through it's address range.


2. *Simple_memory_access* starts simulating the memory (ROM and RAM).

3. *Clock_ESP_*: Using a NodeMCU board which was lying around to simulate the clock.

Olivier J.
