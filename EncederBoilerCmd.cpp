/*
 * File:   EncederBoilerCmd.cpp
 * Author: atoms
 *
 * Created on April 7, 2010, 10:46 PM
 */

#include "EncederBoilerCmd.h"
#include <string.h>
#include <stdio.h>

EncederBoilerCmd::EncederBoilerCmd(Model* model, Controller* controller) {
    this->procesa = false;
    this->controller = controller;
    this->model = model;
}

EncederBoilerCmd::~EncederBoilerCmd() {
}

void EncederBoilerCmd::ok() {
    if (procesa == false) {
        procesa = true;

        if (model->boilerOn == true) {

            model->howTimeOn = 0;
            model->boilerOn = false;
            controller->goHome();
        }
    } else {
        if (model->boilerOn == false && model->howTimeOn > 0) {

            model->boilerOn = true;
            model->whenItStarted = model->current;
            model->whenToturnOff = model->current + (model->howTimeOn*60);
            controller->goHome();
        }

    }






}

void EncederBoilerCmd::cancel() {

    if (model->boilerOn == false) {
        model->howTimeOn = 0;
    }
    controller->goHome();


}

void EncederBoilerCmd::up() {

    if (procesa == false) {

        controller->goX(true);


    } else {
        if (model->boilerOn == false && model->howTimeOn < 60) {

            model->howTimeOn = model->howTimeOn + 1;
        }
    }


}

void EncederBoilerCmd::down() {

    if (procesa == false) {
        controller->goX(false);

    } else {
        if (model->boilerOn == false && model->howTimeOn > 0) {

            model->howTimeOn = model->howTimeOn - 1;
        }

    }

}

void EncederBoilerCmd::display(char msg[]) {
    char integer_string[4];


    sprintf(integer_string, "%d", model->howTimeOn);

    //Limpia string
    strcpy(msg, "");

    if (model->boilerOn == false && procesa == true) {

        strcat(msg, "Encender cuanto tiempo?: ");
        strcat(msg, integer_string);
        strcat(msg, " min");



    } else if (model->boilerOn == false) {
        strcat(msg, "  Encender el      boiler ?");


    } else {
        strcat(msg, "   Apagar el       boiler ?");

    }



}
