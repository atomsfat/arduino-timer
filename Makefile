BOARD := atmega168
AVRDUDE_PORT:=/dev/ttyUSB0
ARDUINO_PATH:=/home/Atoms/bin/arduino-1.0.5/
EXTRA_DIRS=$(ARDUINO_PATH)libraries/LiquidCrystal/
EXTRA_DIRS+=$(ARDUINO_PATH)libraries/EEPROM/
EXTRA_DIRS+=$(ARDUINO_PATH)libraries/Servo/
EXTRA_DIRS+=$(ARDUINO_PATH)libraries/RTClib/
EXTRA_DIRS+=$(ARDUINO_PATH)libraries/Wire/
EXTRA_DIRS+=$(ARDUINO_PATH)libraries/Wire/utility/
include Makefile.mk