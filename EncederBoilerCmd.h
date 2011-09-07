/* 
 * File:   EncederBoilerCmd.h
 * Author: atoms
 *
 * Created on April 7, 2010, 10:46 PM
 */

#ifndef _ENCEDERBOILERCMD_H
#define	_ENCEDERBOILERCMD_H
#include "Command.h"


class EncederBoilerCmd : public Command {
private:
    bool procesa;

public:
    EncederBoilerCmd(Model* model,  Controller* controller);
  
    virtual ~EncederBoilerCmd();

    void ok();
    void cancel();
    void up() ;
    void down();
    void display( char msg[]);



};

#endif	/* _ENCEDERBOILERCMD_H */

