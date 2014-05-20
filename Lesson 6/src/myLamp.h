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
	CGFappearance* whitePlastic;
	CGFappearance* bluePlastic;

	mySemiSphere* base;
	myCylinder* body;
	mySemiSphere* top;

public:
	myLamp();
	virtual ~myLamp();

	void draw();
};

#endif /* MYLAMP_H_ */
