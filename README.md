# A500_BootSel
Simple A500 Floppy boot selector (DF0-DF1 swap).
Revision 3.0 (old ones moved to "Archive").
Main features:
- Can be controlled either by a switch or by RESET (3 times or long press of Ctrl-Amiga-Amiga keys). 
- The switch overrides RESET selection. 
- Bicolor LED can indicate SWAP or NORMAL with different colors. 
- Sound indication of selected configuration  (NORMAL - beep, SWAP - two beeps)

# Circuit diagram

![image](https://github.com/OlegMishin/A500_BootSel/assets/81614352/8c894bfb-adad-4ad5-adfa-43d8f1c22b5a)


# Pcb 3D render

![image](https://github.com/OlegMishin/A500_BootSel/assets/81614352/5fff9c96-fcfd-4002-8ff2-18b6dfeb5f9b)

# MPU firmware
I used IAR AVR IDE but it is quite simple and can be easyly ported to another toolchain. 
Sources included in "Firmware" folder.

