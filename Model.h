/*
 * File:   Model.h
 * Author: atoms
 *
 * Created on March 8, 2010, 11:28 PM
 */

#ifndef _MODEL_H
#define	_MODEL_H
#include <inttypes.h>


class Model {
public:
    //contructor
    Model(int *hora);
    //destructor
    virtual ~Model();

     //variables
    int *hora;
    uint32_t current;

    bool boilerOn;
    int howTimeOn;
    uint32_t whenItStarted;






private:


};

#endif	/* _MODEL_H */

