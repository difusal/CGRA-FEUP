/*
 * MyClock.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: henrique
 */

#include "MyClock.h"

MyClock::MyClock() {
	clockBody = new myCylinder(12, 1, true);

	hoursPtr = new MyClockHand(0.4);
	hoursPtr->setAngle(90);

	minutesPtr = new MyClockHand(0.6);
	minutesPtr->setAngle(180);

	secondsPtr = new MyClockHand(0.7);
	secondsPtr->setAngle(270);

	// Coefficients for clock material
	float amb[3] = { 0.2, 0.2, 0.2 };
	float dif[3] = { 0.6, 0.6, 0.6 };
	float spec[3] = { 0.2, 0.2, 0.2 };
	float shininess = 60.f;

	texture = new CGFappearance(amb, dif, spec, shininess);
	texture->setTexture("res/clock.png");
	texture->setTextureWrap(GL_REPEAT, GL_REPEAT);

	savedTime = 0;
}

void MyClock::update(unsigned long sysTime) {
	if (sysTime != savedTime && savedTime != 0) {
		secondsPtr->incAngle((360.0 / 60) * (sysTime - savedTime) / 1000);
		minutesPtr->incAngle((360.0 / 60) * (sysTime - savedTime) / 1000 / 60);
		hoursPtr->incAngle((360.0 / 12) * (sysTime - savedTime) / 1000 / 3600);
	}

	savedTime = sysTime;
}

void MyClock::draw() {
	glPushMatrix();

	texture->apply();
	clockBody->draw();

	glTranslated(0, 0, 1);
	hoursPtr->draw();
	minutesPtr->draw();
	secondsPtr->draw();

	glPopMatrix();
}

MyClock::~MyClock() {
	delete (clockBody);
	delete (hoursPtr);
	delete (minutesPtr);
	delete (secondsPtr);

	delete (texture);
}
