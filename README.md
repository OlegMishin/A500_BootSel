# A500_BootSel
Simple A500 Floppy boot selector (DF0-DF1 swap).
Can be configured to be controlled by a switch (default) or by triple RESET (Ctrl-Amiga-Amiga). This managed by an ATtiny MPU.

PCB_v2 has minor changes. Mostly silkscreen fixes.

# Default schematic (Switch control)

!![image](https://github.com/OlegMishin/A500_BootSel/assets/81614352/2a4a09f9-5265-4c79-95c2-95dc9ffd01f1)

# Default schematic (Software control with long RESET)

![image](https://github.com/OlegMishin/A500_BootSel/assets/81614352/812ea13d-0646-47b1-908a-81724bf6ed9c)


# Pcb 3D render
Gerbers are in "pcb_v1" folder.
![изображение](https://user-images.githubusercontent.com/81614352/149620833-eb390062-2c70-410a-bab9-8c919594a513.png)

# MPU firmware
I used IAR AVR IDE but it is quite simple and can be easyly ported to another toolchain. 
Sources included in "Firmware" folder.

