/*
 * MyLamp.h
 *
 *  Created on: Mar 28, 2014
 *      Author: henrique
 */

#ifndef MYLAMP_H_
#define MYLAMP_H_

#include "MyHemisphere.h"
#include "MyCylinder.h"
#include "CGFappearance.h"

class MyLamp {
	CGFappearance* whitePlastic;
	CGFappearance* bluePlastic;

	MyHemisphere* base;
	MyCylinder* body;
	MyHemisphere* top;

public:
	MyLamp();
	virtual ~MyLamp();

	void draw();
};

#endif /* MYLAMP_H_ */
