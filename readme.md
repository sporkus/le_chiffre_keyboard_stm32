# Le Chiffre Keyboard - STM32 version
-----------

Open sourced PCB originally design by tominabox1 updated to STM32 MCU.

## Changes
* MCU: STM32F072CBT6 (128Kb flash, built-in DFU bootloader, crystal-less)
* RGB leds changed to SK6812 mini for voltage tolerance
* Roundeded PCB outline
* MX hotswap/Alps

## Firmware
[QMK config](./firmware/le_chiffre_32/) and [vial](./firmware/le_chiffre_32_vial.bin) are available

## Reset buttons
* DFU button is placed in the legacy reset button position. Plug in the board or push the reset button while DFU button is held down to enable DFU mode.

## Fabrication
* verified production files can be found [here](./production)
* pcb dimensions: 84.96x227.34mm
* SK6812 mini 3535 has placement marker on "Data In" pin. Don't confuse it with sk6812-HS mini or sk6812 mini-E.

## PCB
![](./img/pcb_front.png)
![](./img/pcb_back.png)

## Credits
tominabox1 for the [original design](https://github.com/tominabox1/Le-Chiffre-Keyboard)
