BOARD := atmega328
AVRDUDE_PORT:=/dev/ttyUSB0
ARDUINO_PATH:=/Applications/Arduino.app/Contents/Resources/Java/
EXTRA_DIRS=$(ARDUINO_PATH)libraries/LiquidCrystal/
EXTRA_DIRS+=$(ARDUINO_PATH)libraries/Servo/
EXTRA_DIRS+=$(ARDUINO_PATH)libraries/RTClib/
EXTRA_DIRS+=$(ARDUINO_PATH)libraries/Wire/
EXTRA_DIRS+=$(ARDUINO_PATH)libraries/Wire/utility/
include Makefile.mk