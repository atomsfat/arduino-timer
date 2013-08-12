/*
 * File:   Model.cpp
 * Author: atoms
 *
 * Created on March 8, 2010, 11:28 PM
 */

#include "Model.h"
#include <EEPROM.h>

Model::Model() {
 // this->hora = hora;
  this->boilerOn = false;
  this->howTimeOn = 0;
  this->whenToturnOff = 0;

  this-> hourPG1 = EEPROM.read(1);
  this->minutePG1 = EEPROM.read(2);
  this->hourEndPG1 = EEPROM.read(3);
  this->minuteEndPG1 = EEPROM.read(4);
  this->dayPG1 = EEPROM.read(5);

  if(this-> hourPG1 > 24 || this-> minutePG1 > 60){
    this-> hourPG1 = 0;
    this->minutePG1 = 0;
    this->hourEndPG1 = 0;
    this->minuteEndPG1 = 0;
    this->dayPG1 = 0;
  }


}

Model::~Model() {
}

uint32_t Model::startTimePG1(){

}

uint32_t Model::endTimePG1(){

}

void Model::savePG1(){

  EEPROM.write(1,this-> hourPG1 );
  EEPROM.write(2,this->minutePG1 );
  EEPROM.write(3,this->hourEndPG1 );
  EEPROM.write(4,this->minuteEndPG1 );
  EEPROM.write(5,this->dayPG1 );
}


