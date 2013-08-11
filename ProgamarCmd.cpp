/*
 * File:   ProgamarCmd.cpp
 * Author: atoms
 *
 * Created on Agosto 11, 2013, 1:35 PM
 */

#include "ProgramarCmd.h"
#include <string.h>
#include <stdio.h>

ProgramarCmd::ProgramarCmd(Model* model, Controller* controller) {
  this->procesa = false;
  this->controller = controller;
  this->model = model;
}

ProgramarCmd::~ProgramarCmd() {
}

void ProgramarCmd::ok() {
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
      model->whenToturnOff = model->current + (model->howTimeOn * 60);
      controller->goHome();
    }

  }

}

void ProgramarCmd::cancel() {


  controller->goHome();

}

void ProgramarCmd::up() {

  if (procesa == false) {

    controller->goX(true);

  } else {
    if (model->boilerOn == false && model->howTimeOn < 60) {

      model->howTimeOn = model->howTimeOn + 1;
    }
  }

}

void ProgramarCmd::down() {

  if (procesa == false) {
    controller->goX(false);

  } else {
    if (model->boilerOn == false && model->howTimeOn > 0) {

      model->howTimeOn = model->howTimeOn - 1;
    }

  }

}

void ProgramarCmd::display(char msg[]) {


  //Limpia string
  strcpy(msg, "");
  strcat(msg, "Programar encendido automatico ?: ");


}
