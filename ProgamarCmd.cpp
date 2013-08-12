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
  this->procesaHoraInicio = false;
  this->procesaTiempo = false;
  this->procesaDia = false;
  this->controller = controller;
  this->model = model;

  this-> hourPG1 = 0;
  this->minutePG1 = 0;
  this->minutesOnPG1 = 0;
  this->dayPG1 = 0;
}

ProgramarCmd::~ProgramarCmd() {
}

void ProgramarCmd::ok() {

  if (procesa == false && procesaHoraInicio == false && procesaTiempo == false && procesaDia == false) {
    procesa = true;
  } else if (procesa == true && procesaHoraInicio == false && procesaTiempo == false &&  procesaDia == false) {
    procesaHoraInicio = true;



  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == false && procesaDia == false) {
    procesaTiempo = true;

  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == true && procesaDia == false) {
    procesaDia = true;

  }
}

void ProgramarCmd::cancel() {


  controller->goHome();

}

void ProgramarCmd::up() {

  if (procesa == false && procesaHoraInicio == false && procesaTiempo == false && procesaDia == false) {

    controller->goX(true);

  } else if (procesa == true && procesaHoraInicio == false && procesaTiempo == false && procesaDia == false) {
    this->minutePG1 =  this->minutePG1 + 5;
    if(this->minutePG1 >= 60){
      this->hourPG1++;
      this->minutePG1 = 0;
    }
    if(this->hourPG1 >= 24){
      this->hourPG1 = 0;
    }


  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == false &&  procesaDia == false) {
    if ( this->minutesOnPG1 < 60) {

      this->minutesOnPG1  = this->minutesOnPG1  + 1;
      }

  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == true && procesaDia == false) {


  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == true && procesaDia == true) {


  }


}

void ProgramarCmd::down() {

  if (procesa == false && procesaHoraInicio == false && procesaTiempo == false && procesaDia == false) {

    controller->goX(true);

  } else if (procesa == true && procesaHoraInicio == false && procesaTiempo == false && procesaDia == false) {
    this->minutePG1 =  this->minutePG1 - 5;
    if(this->minutePG1 <= 0){
      this->hourPG1--;
      this->minutePG1 = 59;
    }
    if(this->hourPG1 >= 0){
      this->hourPG1 = 23;
    }


  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == false &&  procesaDia == false) {

    if ( this->minutesOnPG1 > 0) {

      this->minutesOnPG1= this->minutesOnPG1 - 1;
      }
  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == true && procesaDia == false) {


  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == true && procesaDia == true) {


  }

}

void ProgramarCmd::display(char msg[]) {


  //Limpia string
  strcpy(msg, "");


  if (procesa == false && procesaHoraInicio == false && procesaTiempo == false && procesaDia == false) {
    strcat(msg, "  Programar      encendido ?: ");

  } else if (procesa == true && procesaHoraInicio == false && procesaTiempo == false &&  procesaDia == false) {
    char hour[4];
    char minute[4];
    sprintf(hour, "%d", this->hourPG1);
    sprintf(minute, "%d", this->minutePG1);

    strcat(msg, "    Hora de     encendido? ");
    strcat(msg, hour);
    strcat(msg, ":");
    strcat(msg, minute);


  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == false && procesaDia == false) {
    char onTime[4];
    sprintf(onTime, "%d", this->minutesOnPG1);
    strcat(msg, "Tiempo encendido?: ");
    strcat(msg, onTime);
     strcat(msg, " min  ");


  } else if (procesa == true && procesaHoraInicio == true && procesaTiempo == true && procesaDia == false) {
    strcat(msg, "   Que dia: ?   ");
    strcat(msg, " D L M M J V S");

  }else if (procesa == true && procesaHoraInicio == true && procesaTiempo == true && procesaDia == true) {
    strcat(msg, "Registro guardado exitosomante   ");


  }

}



