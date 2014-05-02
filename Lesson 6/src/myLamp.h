/*
 * myLamp.h
 *
 *  Created on: Mar 28, 2014
 *      Author: henrique
 */

#ifndef MYLAMP_H_
#define MYLAMP_H_

#include "mySemiSphere.h"
#include "myCylinder.h"
#include "CGFappearance.h"

class myLamp {
	mySemiSphere* base;
	myCylinder* body;
	mySemiSphere* top;

	CGFappearance* whitePlastic;
	CGFappearance* bluePlastic;

public:
	myLamp();
	virtual ~myLamp();

	void draw();
};

#endif /* MYLAMP_H_ */
