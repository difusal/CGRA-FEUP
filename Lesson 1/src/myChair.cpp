#include "myChair.h"

myChair::myChair()
{
	size = 2;
	height = 2;

	double minAngle = -20;
	double maxAngle = 20;
	angle = (rand() % (int)(maxAngle-minAngle)) + minAngle;

	double minTrans = -0.2;
	double maxTrans = 1.5;
	transl = (rand() % (int)(maxTrans-minTrans)) + minTrans;
}

myChair::~myChair(void)
{
}

void myChair::draw()
{
	// applying chair random rotation and translation
	glPushMatrix();
	glTranslated(0, 0, transl);
	glRotated(angle, 0, 1, 0);

	// pernas
	glPushMatrix();
	glTranslated(size/2, height/2, size/2);
	glScaled(0.3, height, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(size/2, height/2, -size/2);
	glScaled(0.3, height, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-size/2, height/2, -size/2);
	glScaled(0.3, height, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-size/2, height/2, size/2);
	glScaled(0.3, height, 0.3);
	cube.draw();
	glPopMatrix();

	// assento
	glPushMatrix();
	glTranslated(0, height, 0);
	glScaled(size, 0.3, size);
	cube.draw();
	glPopMatrix();

	// encosto
	glPushMatrix();
	glTranslated(0, height + size/2, size/2);
	glScaled(size, size, 0.3);
	cube.draw();
	glPopMatrix();

	glPopMatrix();
}
