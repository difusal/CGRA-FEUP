/*
 * MyClockHand.h
 *
 *  Created on: Apr 17, 2014
 *      Author: henrique
 */

#ifndef MYCLOCKHAND_H_
#define MYCLOCKHAND_H_

#include "MyCylinder.h"
#include "CGFappearance.h"

class MyClockHand {
private:
	CGFappearance* texture;
	MyCylinder* pointer;
	float size, angle;

public:
	MyClockHand(float size);
	void draw();
	virtual ~MyClockHand();

	float getAngle();
	void setAngle(float angle);
	void incAngle(float angle);
};

#endif /* MYCLOCKHAND_H_ */
