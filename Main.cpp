#include <WProgram.h>

//#include <Wire.h>
#include <stdlib.h>


//http://tushev.org/articles/electronics/48-arduino-and-watchdog-timer
//http://blog.bricogeek.com/noticias/arduino/como-utilizar-watchdog-con-arduino/
//watch dog
#include <avr/wdt.h>

#include "LiquidCrystal.h"
#include "Servo.h"

#include "Controller.h"
#include "Model.h"


//ds1307 library
//#include "RTClib.h"

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

int rtc2[7]; //this is for store the hour

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


Model* model = new Model( rtc2);
Controller controller(model);

Servo myservo;

char message[40] = "";

// constants won't change. They're used here to
// set pin numbers:
const int buttonUp = 8;
const int buttonDown = 9;

const int buttonOk = 7;
const int buttonCancel = 6;



// variables will change:
int minServo = 5; //
int maxServo = 180;

//
RTC_DS1307 RTC;

void setup() {
	wdt_disable();
	// initialize the pushbutton as input
	pinMode(buttonDown, INPUT);
	pinMode(buttonUp, INPUT);
	pinMode(buttonOk, INPUT);
	pinMode(buttonCancel, INPUT);


    Wire.begin();
    RTC.begin();

	   if (! RTC.isrunning()) {
	    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
	    RTC.adjust(DateTime(__DATE__, __TIME__));
      }


	//this because the default home is no always the same for lcds


	myservo.attach(10);  //set servo to pin 10
	lcd.begin(1, 2);    // configure lcd
	//controller.display(hola);

	wdt_enable(WDTO_2S);

}



void loop()

{

	wdt_reset();

	model->current =  RTC.now();


	// read the state of the pushbutton
	if (digitalRead(buttonDown)) {
		controller.pressDown();

	} else if (digitalRead(buttonUp) == 1) {
		controller.pressUp();
	} else if (digitalRead(buttonOk) == 1) {
		controller.pressOk();
	} else if (digitalRead(buttonCancel) == 1) {
		controller.pressCancel();
	}

	if(model->boilerOn){
		myservo.write(maxServo);
	}else{
		myservo.write(minServo);
	}

	 controller.display(message);

	 lcd.clear();
	 lcd.setCursor(4,0);

	  for(int i=0; i< strlen(message); i++){

	            if((i+1)%17==0){
	                 lcd.setCursor(4,1);
	            }
	            lcd.print(message[i]);

	        }



	delay(100);


}

int main(void) {
	init();

	setup();

	for (;;)
		loop();

	return 0;
}
