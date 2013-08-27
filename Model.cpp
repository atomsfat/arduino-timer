/*
 * File:   Model.cpp
 * Author: atoms
 *
 * Created on March 8, 2010, 11:28 PM
 */

#include "Model.h"


Model::Model() {
 // this->hora = hora;
  this->boilerOn = false;
  this->howTimeOn = 0;
  this->whenItStarted = 0;
  this->whenToturnOff = 0;


  for(int i=0;i<2;i++){
	  this->programs[i].hourPG1 = 0;
	  this->programs[i].minutePG1 = 0;
	  this->programs[i].minutesOnPG1 = 0;
	  this->programs[i].dayPG1 = 0;
	  if(this->programs[i].hourPG1 > 24 || this->programs[i].minutePG1> 60){
		  this->programs[i].hourPG1= 0;
		  this->programs[i].minutePG1= 0;
		  this->programs[i].minutesOnPG1 = 0;

	  }
	  if(this->programs[i].dayPG1>127){
		  this->programs[i].dayPG1 = 0;
	  }
  }


}

Model::~Model() {
}



void Model::savePG1(){

//  EEPROM.write(1,this-> hourPG1 );
//  EEPROM.write(2,this->minutePG1 );
//  EEPROM.write(3,this->minutesOnPG1 );
//  EEPROM.write(4,this->dayPG1 );
}


