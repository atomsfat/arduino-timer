Arduino timer
=============
This is a configurable timer using arduino, rtc (DS1307) and a lcd display
For debian and ubuntu install avr-compiler
```js
apt-get install avrdude binutils-avr gcc-avr avr-libc gdb-avr
```
Install eclipse-cpp
Configure the project:
File>Project>Makefile with existing source
Install arduino-022
Change the following in the Makefile
ARDUINO_PATH
AVRDUDE_PORT
AVR_TOOLS_PATH
