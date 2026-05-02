#!/usr/bin/bash

rm -rf ~/keyboard/le_chiffre_keyboard_stm32/firmware
mkdir ./firmware
cp -r ~/code/qmk_userspace/keyboards/sporkus/le_chiffre_32/* ./firmware/
rm -rf ./firmware/keymaps/sporkus/
cd ~/code/vial-qmk && make sporkus/le_chiffre_32:vial && cp ~/code/vial-qmk/sporkus_le_chiffre_32_vial.bin ~/keyboard/le_chiffre_keyboard_stm32/firmware/
