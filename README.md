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


# Pcb 3D render and actual sample

![image](https://github.com/OlegMishin/A500_BootSel/assets/81614352/5fff9c96-fcfd-4002-8ff2-18b6dfeb5f9b)

![image](https://github.com/OlegMishin/A500_BootSel/assets/81614352/33181fbf-cae7-44a3-bc28-dbcc9168d84f)

![image](https://github.com/OlegMishin/A500_BootSel/assets/81614352/c824fa29-4beb-4a27-900e-5a95ed1a03fa)


# MPU firmware
Is in "Firmware" folder. There is a programming CMD file "EXA-PROG.cmd" to flash the firmware with AVRDUDE.
MCU fuses left by default.

Programming tool: EXA_PROG: https://www.diamex.de/dxshop/EXA-PROG-AVR-ISP-und-UPDI-STM32-NXP-ESP

Also a simple FT232RL based UPDI programmer can be used. More information can be found here:

https://github.com/SpenceKonde/AVR-Guidance/blob/master/UPDI/jtag2updi.md
or here

https://teddywarner.org/Projects/SerialUPDI/

For this tool there is a script "serialupdi.cmd" for flashing with AVRDUDE.

