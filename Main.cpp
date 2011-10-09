#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

#include <stdio.h>
#include <string.h>

#include "Controller.h"
#include "Model.h"

using namespace std;
int rtc2[7]; //this is for store the hour

Model* model = new Model(rtc2);
Controller controller(model);

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
int option;


time_t seconds;
void setup() {

}

void loop()

{
	cout << "Please enter an integer value: ";
	cin >> option;

	seconds = time(NULL);

	model->current = seconds;

	cout << model->current << "\n" ;

	// read the state of the pushbutton
	if (option == 1) {
		controller.pressDown();

	} else if (option== 2) {
		controller.pressUp();
	} else if (option == 3) {
		controller.pressOk();
	} else if (option == 4) {
		controller.pressCancel();
	} else if( option ==5){

	}

	if (model->boilerOn) {

	} else {

	}

	controller.display(message);


	//cout << message << "\n";


	for(int i=0; i< strlen(message); i++){

		            if((i+1)%17==0){
		            	 cout  << "\n";
		            }

		            cout << message[i] ;
	}


	cout << "\n";
//
//	if (strlen(message) <= 17) {
//		lcd.setCursor(4, 1);
//
//		//lcd.print(dt7.year(), DEC);
//		//lcd.print('/');
//		// lcd.print(dt7.month(), DEC);
//		// lcd.print('/');
//		// lcd.print(dt7.day(), DEC);
//		// lcd.print(' ');
//
//
//		lcd.print(current.hour(), DEC);
//		lcd.print(':');
//		lcd.print(current.minute(), DEC);
//		lcd.print(':');
//		lcd.print(current.second(), DEC);
//
//	}

	//delay(500);

}

int main(void) {

	setup();

	for (;;)
		loop();

	return 0;
}
