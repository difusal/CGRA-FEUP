/*
 * MyClock.h
 *
 *  Created on: Apr 9, 2014
 *      Author: henrique
 */

#ifndef MYCLOCK_H_
#define MYCLOCK_H_

#include "MyCylinder.h"
#include "MyClockHand.h"
#include "CGFappearance.h"

class MyClock {
private:
	CGFappearance* texture;
	MyCylinder* clockBody;
	MyClockHand* hoursPtr;
	MyClockHand* minutesPtr;
	MyClockHand* secondsPtr;

	unsigned long savedTime;

public:
	MyClock();
	void update(unsigned long sysTime);
	void draw();
	virtual ~MyClock();

	int clockIsOn;
};

#endif /* MYCLOCK_H_ */
