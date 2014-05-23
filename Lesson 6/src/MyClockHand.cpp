/*
 * MyClockHand.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: henrique
 */

#include "MyClockHand.h"

MyClockHand::MyClockHand(float size) {
	float amb[3] = { 0.2, 0.2, 0.2 };
	float dif[3] = { 0.1, 0.1, 0.1 };
	float spec[3] = { 0.2, 0.2, 0.2 };
	float shininess = 60.f;
	texture = new CGFappearance(amb, dif, spec, shininess);

	pointer = new MyCylinder(12, 1, 1);
	this->size = size;
	angle = 0;
}

void MyClockHand::draw() {
	glPushMatrix();

	texture->apply();

	glRotated(-angle, 0, 0, 1);
	glRotated(-90, 1, 0, 0);
	glScaled(0.02, 0.02, size);
	pointer->draw();

	glPopMatrix();
}

MyClockHand::~MyClockHand() {
	delete (pointer);
	delete (texture);
}

float MyClockHand::getAngle() {
	return angle;
}

void MyClockHand::setAngle(float angle) {
	this->angle = angle;
}

void MyClockHand::incAngle(float angle) {
	this->angle += angle;
	if (this->angle >= 360)
		this->angle -= 360;
}
