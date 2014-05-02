/*
 * myLamp.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: henrique
 */

#include "myLamp.h"

// Coefficients for white plastic
float whitePlasticAmb[3] = { 0.2, 0.2, 0.2 };
float whitePlasticDif[3] = { 0.9, 0.9, 0.9 };
float whitePlasticSpec[3] = { 0.5, 0.5, 0.5 };
float whitePlasticShininess = 60.f;

// Coefficients for blue plastic
float bluePlasticAmb[3] = { 0, 0, 0.2 };
float bluePlasticDif[3] = { 0.4, 0.4, 0.8 };
float bluePlasticSpec[3] = { 0.2, 0.2, 0.2 };
float bluePlasticShininess = 120.f;

myLamp::myLamp() {
	int slices = 30;

	base = new mySemiSphere(slices, 30, true);
	body = new myCylinder(slices, 30, true);
	top = new mySemiSphere(slices, 30, true);

	whitePlastic = new CGFappearance(whitePlasticAmb, whitePlasticDif,
			whitePlasticSpec, whitePlasticShininess);
	bluePlastic = new CGFappearance(bluePlasticAmb, bluePlasticDif,
			bluePlasticSpec, bluePlasticShininess);
}

myLamp::~myLamp() {
	delete (base);
	delete (body);
	delete (top);

	delete (whitePlastic);
}

void myLamp::draw() {
	double baseRadius = 0.7;
	double baseHeight = 0.2;
	double bodyRadius = 0.15;
	double bodyHeight = 1;
	double topRadius = 0.8;

	glPushMatrix();
	glScaled(baseRadius, baseHeight, baseRadius);
	glRotated(-90, 1, 0, 0);
	whitePlastic->apply();
	base->draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(bodyRadius, bodyHeight, bodyRadius);
	glRotated(-90, 1, 0, 0);
	body->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, bodyHeight, 0);
	glScaled(topRadius, 1, topRadius);
	glRotated(-90, 1, 0, 0);
	bluePlastic->apply();
	top->draw();
	glPopMatrix();
}
