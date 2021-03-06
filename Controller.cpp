/*
 * File:   Controller.cpp
 * Author: atoms
 *
 * Created on April 4, 2010, 12:10 PM
 */

#include "Controller.h"
#include "HomeCmd.h"
#include "EncederBoilerCmd.h"
#include "ProgramarCmd.h"
#include <stdlib.h>


Controller::Controller(Model* model) {
	this->model = model;
	this->x = 0;
	this->current = new HomeCmd(model, this);

}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

void Controller::pressOk() {
	current->ok();
}

void Controller::pressUp() {
	current->up();
}

void Controller::pressDown() {
	current->down();
}

void Controller::pressCancel() {
	current->cancel();
}

void Controller::display(char msg[]) {

	this->processCommand();
	current->display(msg);
}

void Controller::goX(bool right) {

	if (right) {
		if (this->x <= 1) {
			this->x++;
		} else {
			this->x = 0;
		}

	} else {

		if (this->x == 0) {
			this->x = 2;
		} else {
			this->x--;
		}
	}

	this->getCommand(x);

}

void Controller::getCommand(int i) {

	//   using namespace std;
	switch (i) {

	case 0:
		delete (current);

		current = new HomeCmd(model, this);

		break;

	case 1:
		delete (current);

		current = new ProgramarCmd(model, this);
		break;

	case 2:

		delete (current);

		current = new EncederBoilerCmd(model, this);
		break;

	}
}

void Controller::goHome() {

	this->getCommand(0);

}

void Controller::processCommand() {




}

