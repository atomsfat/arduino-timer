/* 
 * File:   HomeCmd.h
 * Author: atoms
 *
 * Created on April 2, 2010, 11:39 AM
 */

#ifndef _HOMECMD_H
#define	_HOMECMD_H
#include "Command.h"


class HomeCmd : public Command {
private:

public:
    HomeCmd(Model* model,  Controller* controller);

    virtual ~HomeCmd();


    void ok();
    void cancel();
    void up();
    void down();
    void display(char msg[]);


};

#endif	/* _HOMECMD_H */

