#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "LiquidCrystal.h"
#include <Wire.h>

#include <stdlib.h>
#include <RTClib.h>

#include "Controller.h"
#include "Model.h"

#include "Servo.h"

// prototypes
void * operator new(size_t size);
void operator delete(void * ptr);
//enable inherance
__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release(__guard *);
extern "C" void __cxa_guard_abort(__guard *);

//normal
void setup();
void loop();

//this enable new operator
void * operator new(size_t size) {
	return malloc(size);
}
//this enable delete operator
void operator delete(void * ptr) {
	free(ptr);
}

int __cxa_guard_acquire(__guard *g) {
	return !*(char *) (g);
}
;
void __cxa_guard_release(__guard *g) {
	*(char *) g = 1;
}
;
void __cxa_guard_abort(__guard *) {
}
;

extern "C" void __cxa_pure_virtual() {
	cli();
	for (;;)
		;
}

//Here my program start
Servo myservo;
// variables will change:
int minServo = 5; //
int maxServo = 175;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Model* model = new Model();
Controller controller(model);

char message[40] = "";

// constants won't change. They're used here to
// set pin numbers:
const int buttonUp = 8;
const int buttonDown = 9;

const int buttonOk = 7;
const int buttonCancel = 10;

RTC_DS1307 RTC;
DateTime current;

void setup() {

	// initialize the pushbutton as input
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH);

	pinMode(buttonDown, INPUT);
	pinMode(buttonUp, INPUT);
	pinMode(buttonOk, INPUT);
	pinMode(buttonCancel, INPUT);

	Wire.begin();
	RTC.begin();
	// configure display
	lcd.begin(1, 2);

	myservo.attach(6); //set servo to pin 10


	uint8_t buffer[8];
	RTC.readMemory(0, buffer, 8);

	for (int i = 0; i < 2; i++) {

		int offset = i * 4;

		model->programs[i].hourPG1 = buffer[offset];
		model->programs[i].minutePG1 = buffer[offset + 1];
		model->programs[i].minutesOnPG1 = buffer[offset + 2];
		model->programs[i].dayPG1 = buffer[offset + 3];

		if (model->programs[i].hourPG1 > 24 || model->programs[i].minutePG1
				> 60) {
			model->programs[i].hourPG1 = 0;
			model->programs[i].minutePG1 = 0;
			model->programs[i].minutesOnPG1 = 0;

		}
		if (model->programs[i].dayPG1 > 127) {
			model->programs[i].dayPG1 = 0;
		}
	}

}

void loop()

{

	uint8_t pg1[8];

	for (int i = 0; i < 2; i++) {

		int offset = i * 4;
		pg1[0 + offset] = model->programs[i].hourPG1;
		pg1[1 + offset] = model->programs[i].minutePG1;
		pg1[2 + offset] = model->programs[i].minutesOnPG1;
		pg1[3 + offset] = model->programs[i].dayPG1;

	}

	RTC.writeMemory(0, pg1, 8);

	current = RTC.now();

	model->current = current.unixtime();

	// read the state of the pushbutton
	if (digitalRead(buttonDown) == 1) {
		controller.pressDown();
	} else if (digitalRead(buttonUp) == 1) {
		controller.pressUp();
	} else if (digitalRead(buttonOk) == 1) {
		controller.pressOk();
	} else if (digitalRead(buttonCancel) == 1) {
		controller.pressCancel();
	}

	if (model->boilerOn) {
		myservo.write(maxServo);
	} else {
		myservo.write(minServo);
	}

	int dow = current.dayOfWeek();

	for (int i = 0; i < 2; i++) {
		if ( model->programs[i].hourPG1 > 0 &&  model->programs[i].minutePG1 > 0 &&  model->boilerOn
				== false) {
			DateTime dt0(current.year(), current.month(), current.day(),
					 model->programs[i].hourPG1,  model->programs[i].minutePG1, 0);

			int tD =  model->programs[i].dayPG1 & 1; //Domingo
			int tL =  model->programs[i].dayPG1 & 2;
			int tM =  model->programs[i].dayPG1 & 4;
			int tMi = model->programs[i].dayPG1 & 8;
			int tJ =  model->programs[i].dayPG1 & 16;
			int tV =  model->programs[i].dayPG1 & 32;
			int tS =  model->programs[i].dayPG1 & 64;

			if (dow == 0) {
				if (tD == 1) {
					model->whenItStarted = dt0.unixtime();
					model->whenToturnOff = model->whenItStarted
							+ (model->programs[i].minutesOnPG1 * 60);
				}
			} else if (dow == 1) { //lunes
				if (tL == 2) {
					model->whenItStarted = dt0.unixtime();
					model->whenToturnOff = model->whenItStarted
							+ (model->programs[i].minutesOnPG1 * 60);
				}

			} else if (dow == 2) {
				if (tM == 4) {
					model->whenItStarted = dt0.unixtime();
					model->whenToturnOff = model->whenItStarted
							+ (model->programs[i].minutesOnPG1 * 60);
				}

			} else if (dow == 3) {
				if (tMi == 8) {
					model->whenItStarted = dt0.unixtime();
					model->whenToturnOff = model->whenItStarted
							+ (model->programs[i].minutesOnPG1 * 60);
				}

			} else if (dow == 4) {
				if (tJ == 16) {
					model->whenItStarted = dt0.unixtime();
					model->whenToturnOff = model->whenItStarted
							+ (model->programs[i].minutesOnPG1 * 60);
				}

			} else if (dow == 5) {
				if (tV == 32) {
					model->whenItStarted = dt0.unixtime();
					model->whenToturnOff = model->whenItStarted
							+ (model->programs[i].minutesOnPG1 * 60);
				}
			} else if (dow == 6) {
				if (tS == 64) {
					model->whenItStarted = dt0.unixtime();
					model->whenToturnOff = model->whenItStarted
							+ (model->programs[i].minutesOnPG1 * 60);
				}
			}
		}
	}

	if (model->current > model->whenItStarted && model->current
			< model->whenToturnOff) {
		model->boilerOn = true;
	} else {
		model->boilerOn = false;
	}

	controller.display(message);

	//  lcd.clear();
	lcd.setCursor(0, 0);

	for (int i = 0; i < strlen(message); i++) {

		if ((i + 1) % 17 == 0) {
			lcd.setCursor(0, 1);
		}
		lcd.print(message[i]);

	}

	if (strlen(message) <= 17) {
		lcd.setCursor(0, 1);

		//lcd.print(dt7.year(), DEC);
		//lcd.print('/');
		// lcd.print(dt7.month(), DEC);
		// lcd.print('/');
		// lcd.print(dt7.day(), DEC);
		// lcd.print(' ');

		//		lcd.print(dow, DEC);
		//
		//		lcd.print(' ');


		lcd.print("    ");
		lcd.print(current.hour(), DEC);
		lcd.print(':');
		lcd.print(current.minute(), DEC);
		lcd.print(':');
		lcd.print(current.second(), DEC);
		lcd.print("    ");

	}

	delay(200);

}

int main(void) {
	init();

	setup();

	for (;;)
		loop();

	return 0;
}
