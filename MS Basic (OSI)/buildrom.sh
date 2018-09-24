#!/usr/bin/env bash


echo "Building the MS Basic Rom"
echo "Compiling"
ca65 osi_bas.s -o osi_bas.o -l
echo "Linking"
ld65 -C osi_bas.cfg osi_bas.o -o osi_bas.bin
echo "Done"
