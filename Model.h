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

	struct PG {
		uint8_t hourPG1;
		uint8_t minutePG1;
		uint8_t minutesOnPG1;
		uint8_t dayPG1;
	};
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

//	uint8_t hourPG1;
//	uint8_t minutePG1;
//	uint8_t minutesOnPG1;
//	uint8_t dayPG1;

	struct PG programs[2];

	void savePG1();

private:

};

#endif	/* _MODEL_H */

