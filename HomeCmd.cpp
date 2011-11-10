/*
 * File:   HomeCmd.cpp
 * Author: atoms
 *
 * Created on April 2, 2010, 11:39 AM
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "HomeCmd.h"


HomeCmd::HomeCmd(Model* model, Controller* controller) {

    this->model = model;
    this->controller = controller;
    std::cout << " constructor2 "<< this->controller << " "<<this->model <<"\n";
}

HomeCmd::~HomeCmd() {
}

void HomeCmd::ok() {
	std::cout << " ok homeCmd \n";
}

void HomeCmd::cancel() {
	std::cout << " cancel homeCmd \n";
}

void HomeCmd::up() {
	std::cout << " up homeCmd \n";
    controller->goX(false);

}

void HomeCmd::down() {
	std::cout << " down homeCmd \n";
 //   controller->goX(true);
}

void HomeCmd::display(char msg[]) {


	std::cout << " display homeCmd \n";
    char integer_string_howTimeOn[20];


    int timeOn = (model->whenToturnOff-model->currentTime);
    //sprintf(integer_string_howTimeOn, "%d", timeOn);

   // Limpia string
    strcpy(msg, "");


    if (model->boilerOn) {

        strcat(msg, "Boiler encedido   por: ");
        strcat(msg, integer_string_howTimeOn);
        strcat(msg, " seg");


    } else {
        strcat(msg, " Boiler apagado");

    }
}
