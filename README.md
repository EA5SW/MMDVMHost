These are the source files for building the MMDVMHost, the program that interfaces to the MMDVM or DVMega on the one side, and a suitable network on the other. It supports D-Star, DMR, P25 Phase 1, and System Fusion.

On the D-Star side the MMDVMHost interfaces with the ircDDB Gateway, on DMR it can connect to BrandMeister, DMR+, HB Link, XLX or [DMRGateway](https://github.com/g4klx/DMRGateway) (to connect to multiple DMR networks at once) on System Fusion it connects to the YSF Gateway. On P25 it connects to the P25 Gateway.

It builds on 32-bit and 64-bit Linux as well as on Windows using Visual Studio 2017 on x86 and x64. It can optionally control various Displays. Currently these are:

- HD44780 (sizes 2x16, 2x40, 4x16, 4x20)
	- Support for HD44780 via 4 bit GPIO connection (user selectable pins)
	- Adafruit 16x2 LCD+Keypad Kits (I2C)
	- Connection via PCF8574 GPIO Extender (I2C)
- Nextion TFTs (sizes 2.4", 2.8", 3.2" and 3.5")
- TFT display sold by Hobbytronics in UK
- OLED 128x64 (SSD1306)
- LCDproc

The Nextion displays can connect to the UART on the Raspberry Pi, or via a USB to TTL serial converter like the FT-232RL. It may also be connected to the UART output of the MMDVM modem (Arduino Due, STM32, Teensy), or to the UART output on the UMP.

The HD44780 displays are integrated with wiringPi for Raspberry Pi based platforms.

The Hobbytronics TFT Display, which is a Pi-Hat, connects to the UART on the Raspbery Pi.

The OLED display needs a extra library see OLED.md

The LCDproc support enables the use of a multitude of other LCD screens. See the [supported devices](http://lcdproc.omnipotent.net/hardware.php3) page on the LCDproc website for more info.

This software is licenced under the GPL v2 and is intended for amateur and educational use only. Use of this software for commercial purposes is strictly forbidden.


********* Special notes EA5SW mods **************

All of this mods are build and tested ONLY in a Rapsberry Pi 2 and 3.
It's possible that don't work with another hardware.


New TTS (Text To Speech) callsigns via Festival are coded into the software and are ALWAYS active via internal card output

All the callsigns are speaked into ICAO code. 

Installation in Raspberry Pi:

sudo apt-get install festival

Default voices are english.

if you want spanish voices install packages for Guadalinex:
https://github.com/guadalinex-archive/hispavoces

wget https://github.com/guadalinex-archive/hispavoces/raw/master/packages/festvox-palpc16k_1.0.0_all.deb

wget https://github.com/guadalinex-archive/hispavoces/raw/master/packages/festvox-sflpc16k_1.0.0_all.deb

sudo dpkg -i festvox-sflpc16k_1.0.0_all.deb

sudo dpkg -i festvox-palpc16k_1.0.0_all.deb



edit festival.scm and put last line prefered voice:

sudo nano /etc/festival.scm

Copy & paste those lines:

;;(set! voice_default 'voice_JuntaDeAndalucia_es_sf_diphone)

(set! voice_default 'voice_JuntaDeAndalucia_es_pa_diphone)

I prefer down sample rate at 14500Hz to slow a bit the voice:

(Parameter.set 'Audio_Command "aplay -q -c 1 -t raw -f s16 -r 14500 $FILE")

The code for voice are written into Display.cpp
The phonetic in spanish changed, for example, Mike in spanish are best "Maik"

search this lines to see how modify:

else if (c == 'M'){

strcat(voice," Maik ");


I put all operations in RAMDISK to no write or read on SD card, create a simple bash to execute before MMDVMHost to create a small ramdisk of 120K (or minor)

#!/bin/bash

sudo mkdir -p /ram

sudo mount -t tmpfs -o size=120k tmpfs /ram

sudo touch /ram/mm_voice.sh

sudo chmod 777 /ram/mm_voice.sh




Now Nextion Screen is more complex, all development are made and tested into a Raspberry Pi and use some routines of this hardware. It's possible that only work in Rpi and not in Orange Pi or similar

Are made with DMR only in mind for Hotspots, so only use Timeslot2 and not tested in mixed mode (P25,Dstar,etc) The code made a new screens for Nextion screens.

At this time displays:

Some extra information:: Locator, City and Frequency.

Real IP number at startup of Pi, etho or wlan detects.
Temperature of Raspberry Pi.
Real time Smeter for MMDVM Modems that outs RSSI information (MMDVM modes with radios as Motorola,for example)
Fake Smeters for the rests of types (DVMEGA,HS_HAT,etc)
Change of colors in sequence Idle/RX/TX of Hotspot.
Talker Alias display of information send by master.
Decode of TG number and display of picture associated to this TG.
Now TG's are the EA most used.
Decode of Callsign Prefix and display of picture associated to this Prefix.
Now are the EA,EB & EC prefix
Decode of 9990 and 4000 commands also displaying pictures
Decode of own callsign and display of own picture.
Remote Reboot,Shutdown,Wifi or change of net eligible by sysop via DMR


I add a new entry in MMDVM.ini for path to config files in Nextion section:
FilesConfig=/home/pi/MMDVMHost/etc/

You have now 5 config files (work in progress to put in only one), don't comment or delete any line, the code are simple and need to end with a C/R line to EOF

info.ini contains information for MMDVM home screen:

Callsign Location Frequency DMR Network Name

prefixA.ini, prefixB.ini and prefixC.ini contains a list of prefix to combine for displkay a picture map into a Nextion.
Example: EA-EA9, EB0-EB9,EC0-EC9, are the official prefix for Spain to hams (don't include a special stations)

tg.ini contains the number of the TG's (BrandMeister Network) to display a picture logo into a Nextion.

The first TG number equals to picture 30 into the Nextion tft files.

Nextion tft (compiled) and hmi (source) files contain the pictures to work.

The editable pics are 200x100 and 100x50 pixels

Open the Nextion HMI in Editor and observe the picture list Also Open the Nextion.ini file in a editor to see references

0-19 are semi-fixed pictures, change the 8 & 9 with the replace opcion for your own callsign picture

20-29 are the prefixes pictures 3 diferents prefixes are allocated for every pic, in Nextion.ini section [WPX] you see PXA0,PXB0 and PXC0 and the prefixes EA0 EB0 and EC0 When you transmit or receive a transmission from these prefixes are displayed the pic 20 If the transmission comes from EA2,EB2 or EC2 prefixes, display picture 21 and all others.

The TG list are from picture 30 to picture 137, and works same that prefix, the list are in the tg.ini file.

example: the TG localed in first position are 214, when receive a transmission of this TG displays the picture 30 in the Nextion. 214 (EA national Talkgroup) have the picture 30 example of change: If yoy want receive the 3100 USA Talkgroup replace the image in the Nextion display (picture 30) for a USA Flag, change the entry 214 for 3100 in tg.ini

Remember that any change in tg.ini are needed to change in the Nextion Screen and upload again to the display.

99998 are Shutdown TG to transmit to shutdown the Pi
99999 are Reboot TG to transmit to reboot the Pi
99997 Send mm_plus command to start a new MMDDVMHost in dmrplus mode (mm_plus is an script file)
99996 Send mm_gate command to start a new MMDDVMHost in DMRGateway mode (mm_gate is an script file)
99995 Send mm_BM command to start a new MMDDVMHost in BrandMeister mode (mm_BM is an script file)
99991 Active Wifi Interface
99990 Desactive Wifi Interface


Special notes for OLED displays:


In MMDVM.ini

If Duplex are = 1 the default OLED Layout are use.
If Duplex are = 0 the Layout are change to HotSpot mode

The mods are made with a personal HotSpot in mind. DVMega, MMDVM_HS, low cost or ZumSpot are best candidates.

This code works with DMR SlotTime 2 only, all Slot 1 info are pulled out when are in simplex.

The Talker Alias, IP number and Temperature for Raspberry Pi are added. In Orange Pi the code for temperature works with small changes.
If no temperature file are read, Temp don't display.

Are added some logos for differents networks in 128x26 & 128 x 32 formats for the Idle Screen and small logos(64x16) for the TX/RX screens, also a logos for Parrot and disconnect codes (9990 and 4000)

All TG codes are easy to change into OLED.cpp

Example TG codes:

4000 display a broken chains logo
9990 display a parrot logo
9 or 8 displays a DmrPlus logo into tx/rx screen
6 displays a XLX logo
any other TG display a BrandMeister Logo.

Remote Commands work simply when TX into a determined TG or Private number as works in Nextion displays, same code numbers have hardcoded for all modes of MMDVMHost.

To Compile:

I made a new Makefile, to compile the OLED and Nextion code.
make -f Makefile.EA5SW


