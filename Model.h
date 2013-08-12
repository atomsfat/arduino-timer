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
  Model();
  //destructor
  virtual ~Model();

  //variables
  int *hora;
  uint32_t current;

  bool boilerOn;
  int howTimeOn;
  uint32_t whenItStarted;
  uint32_t whenToturnOff;



  uint32_t startTimePG1();
  uint32_t endTimePG1();
  void savePG1();


private:
   int hourPG1;
   int minutePG1;
   int hourEndPG1;
   int minuteEndPG1;
   int dayPG1;

};

#endif	/* _MODEL_H */

