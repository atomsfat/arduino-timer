/* 
 * File:   Controller.h
 * Author: atoms
 *
 * Created on April 4, 2010, 12:10 PM
 */

#ifndef _CONTROLLER_H
#define	_CONTROLLER_H

#include "Command.h"
#include "Controller.h"

#include "Model.h"
class Command;
class Controller;

class Controller {
public:
    Controller(Model* model);
    Controller(const Controller& orig);
    virtual ~Controller();
    void pressOk();
    void pressUp();
    void pressDown();
    void pressCancel();
    void display(char msg[]);
    void goX(bool right);
    void getCommand(int i);
    void goHome();

private:
    Command* current;
    Model* model;
    int x;
};

#endif	/* _CONTROLLER_H */

