/*
 * File:   HomeCmd.cpp
 * Author: atoms
 *
 * Created on April 2, 2010, 11:39 AM
 */

#include "HomeCmd.h"
#include <string.h>
#include <stdio.h>

HomeCmd::HomeCmd(Model* model, Controller* controller) {

  this->model = model;
  this->controller = controller;
}

HomeCmd::~HomeCmd() {
}

void HomeCmd::ok() {
}

void HomeCmd::cancel() {

}

void HomeCmd::up() {
  controller->goX(true);

}

void HomeCmd::down() {
  controller->goX(false);
}

void HomeCmd::display(char msg[]) {

  char integer_string_howTimeOn[4];

  if(model->current > model->whenToturnOff){
    sprintf(integer_string_howTimeOn, "%d", 0);
  }else{
    int timeOn = (model->whenToturnOff - model->current);
    sprintf(integer_string_howTimeOn, "%d", timeOn);
  }



  //Limpia string
  strcpy(msg, "");

  if (model->boilerOn) {

    strcat(msg, "Boiler encedido   por: ");
    strcat(msg, integer_string_howTimeOn);
    strcat(msg, " seg   ");

  } else {
    strcat(msg, " Boiler apagado ");

  }
}
