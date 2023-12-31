# Le Chiffre Keyboard - STM32 version
-----------

Open sourced PCB originally design by tominabox1 updated to STM32 MCU.

## Design goals
* Drop-in replacement to existing cases
* MCU: STM32F072CBT6 (128Kb flash, built-in DFU bootloader) to allow more firmware features
* MX hotswap, Alps support

## Firmware
* [QMK config](https://github.com/sporkus/qmk_userspace/tree/main/keyboards/sporkus/le_chiffre_32)
* [zmk config](https://github.com/petejohanson/le-chiffre-stm32-zmk-config)
* [pre-compiled vial](./firmware/le_chiffre_32_vial.bin)

To flash initially using dfu-util or qmk toolbox, plug in the board or push the reset button while DFU button is held down.

## Fabrication
* verified production files can be found [here](./pcb_production)
* pcb dimensions: 84.96x227.34mm
* SK6812 mini 3535 has placement marker on "Data In" pin. Don't confuse it with sk6812-HS mini or sk6812 mini-E.

## Misc
#### 3D assembly preview
* [online viewer](https://3dviewer.net/#model=https://github.com/sporkus/le_chiffre_keyboard_stm32/blob/main/documentation/stm32_hotswap_chiffre-3D.step)
* [step assembly](./documentation/stm32_hotswap_chiffre-3D.step)


#### PCB renders
![](./documentation/stm32_hotswap_chiffre-top.jpg)
![](./documentation/stm32_hotswap_chiffre-bottom.jpg)

#### BoM
[interactive BoM](./documentation/stm32_hotswap_chiffre-ibom.html)

#### Schematic
[Schematic pdf](./documentation/stm32_hotswap_chiffre-schematic.pdf)


#### Case
![3d printable case](./case/case.png)

## Credits
tominabox1 for the [original design](https://github.com/tominabox1/Le-Chiffre-Keyboard)

## Changelog
* v0.2.2: change center switch to soldered instead of hotswap. Group buy.
* v0.2.1: added front led bypass jumper
* v0.2.0: improved protection circuit
* v0.1: working initial prototypes
