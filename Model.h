/* 
 * File:   Model.h
 * Author: atoms
 *
 * Created on March 8, 2010, 11:28 PM
 */

#ifndef _MODEL_H
#define	_MODEL_H


class Model {
public:
    //contructor
    Model(int *hora);
    //destructor
    virtual ~Model();

     //variables
    int *hora;


    bool boilerOn;
    int howTimeOn;
    int whenItStarted;

    

    
 

private:

   
};

#endif	/* _MODEL_H */

