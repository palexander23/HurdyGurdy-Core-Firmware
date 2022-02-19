# HurdyGurdy Core Firmware

This Repository contains the firmware running on the Core Control PCB of my Electronic Hurdy Gurdy.
As the name suggests, it will provide the core functionality needed to produce music.
A non-exhaustive list of functions is as follows: 

* Reading button key inputs.
* Reading the crank handle speed.
* Managing the USB MIDI interface.
* Translating musical inputs into transmitted MIDI packets.

I am still in the process of choosing the MCU.
The different investigations into MCUs can be found on separate branches. 

## Install Dependencies
1. Install packages
```bash
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib clang-format
```

2. Install submodules
```bash
git submodule update --init --recursive --jobs 9 --progress 
```
