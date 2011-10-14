/*
 * File:   EncederBoilerCmd.cpp
 * Author: atoms
 *
 * Created on April 7, 2010, 10:46 PM
 */
#include <iostream>
#include <string.h>
#include <stdio.h>

#include "EncederBoilerCmd.h"


EncederBoilerCmd::EncederBoilerCmd(Model* model, Controller* controller) {
    this->procesa = false;
    this->controller = controller;
    this->model = model;
    std::cout << " constructor2 "<< this->controller << " "<<this->model <<"\n";
}

EncederBoilerCmd::~EncederBoilerCmd() {
}

void EncederBoilerCmd::ok() {

	std::cout << " ok EncederBoilerCmd ";
}

void EncederBoilerCmd::cancel() {

	std::cout << " cancel EncederBoilerCmd ";
}

void EncederBoilerCmd::up() {

	std::cout << " up EncederBoilerCmd ";

}

void EncederBoilerCmd::down() {


	std::cout << " down EncederBoilerCmd ";

}

void EncederBoilerCmd::display(char msg[]) {

	std::cout << " display EncederBoilerCmd ";



}
