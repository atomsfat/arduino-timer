/* 
 * File:   ProgamarCmd.h
 * Author: atoms
 *
 * Created on Agosto 11, 2013, 1:35 PM
 */

#ifndef _PROGRAMARCMD_H
#define	_PROGRAMARCMD_H
#include "Command.h"


class ProgramarCmd : public Command {
private:
    bool procesa;

public:
    ProgramarCmd(Model* model,  Controller* controller);
  
    virtual ~ProgramarCmd();

    void ok();
    void cancel();
    void up() ;
    void down();
    void display( char msg[]);



};

#endif	/* _PROGRAMARCMD_H */

