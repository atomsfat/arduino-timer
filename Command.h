/* 
 * File:   Command.h
 * Author: atoms
 *
 * Created on April 2, 2010, 11:32 AM
 */

#ifndef _COMMAND_H
#define	_COMMAND_H
#include "Controller.h"
#include "Model.h"



class Controller;
class Model;

class Command {
protected:
    Controller* controller;
    Model* model;

public:

    virtual void ok() = 0;
    virtual void cancel() = 0;
    virtual void up() = 0;
    virtual void down() = 0;
    virtual void display(char msg[]) = 0;

private:

};

#endif	/* _COMMAND_H */

