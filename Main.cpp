#include <WProgram.h>
#include <stdlib.h>


#include <LiquidCrystal.h>


#include "Controller.h"
#include "Model.h"

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

int rtc[7]; //this is for store the hour

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


Model* model = new Model( rtc);
Controller controller(model);

char message[40] = "Hola mundo";

// constants won't change. They're used here to
// set pin numbers:
const int buttonUp = 8;
const int buttonDown = 9;

const int buttonOk = 7;
const int buttonCancel = 6;



// variables will change:
int minServo = 5; //
int maxServo = 180;

void setup() {

	// initialize the pushbutton as input
//	pinMode(buttonDown, INPUT);
//	pinMode(buttonUp, INPUT);
//	pinMode(buttonOk, INPUT);
//	pinMode(buttonCancel, INPUT);

	//this because the default home is no always the same for lcds


	lcd.begin(1, 2);    // configure lcd
	//controller.display(hola);


}



void loop()

{
//
//
//	// read the state of the pushbutton
//
//	if (digitalRead(buttonDown)) {
//		controller.pressDown();
//
//	} else if (digitalRead(buttonUp) == 1) {
//		controller.pressUp();
//	} else if (digitalRead(buttonOk) == 1) {
//		controller.pressOk();
//	} else if (digitalRead(buttonCancel) == 1) {
//		controller.pressCancel();
//	}
//
//	if(model->boilerOn){
//
//	}else{
//
//	}
//
//	 controller.display(message);
//
//	 lcd.clear();
//	 lcd.setCursor(4,0);
//
//	  for(int i=0; i< strlen(message); i++){
//
//	            if((i+1)%17==0){
//	                 lcd.setCursor(4,1);
//	            }
//	            lcd.print(message[i]);
//
//	        }
//
//
//
//	delay(500);


}

int main(void) {
	//init();

	setup();

	for (;;)
		loop();

	return 0;
}
