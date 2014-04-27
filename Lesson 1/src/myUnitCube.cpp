#include "myUnitCube.h"

myUnitCube::myUnitCube(void)
{
}

myUnitCube::~myUnitCube(void)
{
}

void myUnitCube::draw()
{
	// XY parallel faces
	glPushMatrix();
	glTranslated(0, 0, 0.5);
	glRectd(-0.5, -0.5, 0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -0.5);
	glRectd(-0.5, 0.5, 0.5, -0.5);
	glPopMatrix();

	// XZ parallel faces
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	glRotated(-90, 1, 0, 0);
	glRectd(-0.5, -0.5, 0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -0.5, 0);
	glRotated(-90, 1, 0, 0);
	glRectd(-0.5, 0.5, 0.5, -0.5);
	glPopMatrix();

	// YZ parallel faces
	glPushMatrix();
	glTranslated(0.5, 0, 0);
	glRotated(-90, 0, 1, 0);
	glRectd(-0.5, 0.5, 0.5, -0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5, 0, 0);
	glRotated(-90, 0, 1, 0);
	glRectd(-0.5, -0.5, 0.5, 0.5);
	glPopMatrix();
}
