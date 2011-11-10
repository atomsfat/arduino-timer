#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>

#include <stdio.h>
#include <string.h>


#include "Controller.h"
#include "Model.h"
#include "Command.h"
#include "HomeCmd.h"
#include "EncederBoilerCmd.h"


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



	//any object placed in such a list must be allocated from the heap
	//When the list is destructed, it will leave all of its referenced
	//objects on the heap without calling their destructors or deallocating their memory.

	controller.commands.push_back(new HomeCmd(model, &controller));
	controller.commands.push_back(new EncederBoilerCmd(model, &controller));


	cout << "controller.commands.at(0)->" << controller.commands.at(0)<< "\n";

	controller.commands.at(0)->display(message);
	controller.commands.at(1)->display(message);

	cout << "commands size " << controller.commands.size() << "\n";

}

void loop()

{
	cout << "Please enter an integer value: ";
	cin >> option;

	seconds = time(NULL);

	model->currentTime = seconds;

	cout << model->currentTime << "\n" ;

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

	cout << "data--->" ;

	controller.display(message);





	for(uint i=0; i< strlen(message); i++){

		            if((i+1)%17==0){
		            	 cout  << "\n";
		            }

		            cout << message[i] ;
	}


	cout << "\n";


}

int main(void) {

	setup();

	for (;;)
		loop();

	return 0;
}
