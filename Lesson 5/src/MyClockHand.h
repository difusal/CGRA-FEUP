/*
 * MyClockHand.h
 *
 *  Created on: Apr 17, 2014
 *      Author: henrique
 */

#ifndef MYCLOCKHAND_H_
#define MYCLOCKHAND_H_

#include "myCylinder.h"
#include "CGFappearance.h"

class MyClockHand {
private:
	myCylinder* pointer;
	float size;
	float angle;

	CGFappearance* texture;

public:
	MyClockHand(float size);
	void draw();
	virtual ~MyClockHand();

	float getAngle();
	void setAngle(float angle);
	void incAngle(float angle);
};

#endif /* MYCLOCKHAND_H_ */
