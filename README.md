# A500_BootSel
Simple A500 Floppy boot selector (DF0-DF1 swap).
Can be configured to be controlled by a switch (default) or by triple RESET (Ctrl-Amiga-Amiga). This managed by an ATtiny MPU.


# Default schematic (Switch control)

![изображение](https://user-images.githubusercontent.com/81614352/149620829-915dcd8d-ae16-423c-9a46-15e8e0cebd5f.png)


# Pcb 3D render
![изображение](https://user-images.githubusercontent.com/81614352/149620833-eb390062-2c70-410a-bab9-8c919594a513.png)

# MPU firmware
I used IAR AVR IDE but it is quite simple and can be easyly ported to another toolchain. 
Sources included in "Firmware" folder.

