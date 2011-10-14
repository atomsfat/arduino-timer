/*
 * File:   Controller.cpp
 * Author: atoms
 *
 * Created on April 4, 2010, 12:10 PM
 */
#include <stdlib.h>
#include <iostream>

#include "Controller.h"
#include "HomeCmd.h"
#include "Command.h"
#include "EncederBoilerCmd.h"

using namespace std;
Controller::Controller(Model* model) {
	this->model = model;
	this->x = 0;
	this->current = 0;

}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

void Controller::pressOk() {
	cout << " ctrl ok \n";
	commands.at(current)->ok();
}

void Controller::pressUp() {
	cout << " ctrl up \n";
	commands.at(current)->up();
}

void Controller::pressDown() {
	cout << " ctrl down \n";
	commands.at(current)->down();
}

void Controller::pressCancel() {
	cout << " ctrl cancel \n";
	commands.at(current)->cancel();
}

void Controller::display(char msg[]) {
	cout << " ctrl display \n";
	cout << " current: " << current << "\n";
	//this->processCommand();

	commands.at(1)->display(msg);
	cout << " ************* \n";

}

void Controller::goX(bool right) {

	cout << " goX " << " \n";
	if (right) {
		if (x < 1) {
			x++;
		} else {
			x = 0;
		}

	} else {

		if (x > 0) {
			x--;
		} else {
			x = 1;
		}
	}

	this->getCommand(x);

}

void Controller::getCommand(int i) {

	cout << " size getCommand " << i <<  " commands.size() " << commands.size() << " \n";
	switch (i) {

	case 0:

		current = 0;
		break;

	case 1:

		current = 1;
		break;
	}
}

void Controller::goHome() {

	this->getCommand(0);

}

void Controller::processCommand() {

//	if ((model->current) > (model->whenItStarted + (model->howTimeOn * 60))) {
//
//		model->boilerOn = false;
//
//	}

	if (model->boilerOn) {
		if (model->whenToturnOff < model->current) {
			model->boilerOn = false;
		}

	}

}

