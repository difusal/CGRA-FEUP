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
	glNormal3f(0, 0, 1);
	glRectd(-0.5, -0.5, 0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
	glRotated(180, 1, 0, 0);
	glTranslated(0, 0, 0.5);
	glNormal3f(0, 0, 1);
	glRectd(-0.5, -0.5, 0.5, 0.5);
	glPopMatrix();

	// XZ parallel faces
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	glRotated(-90, 1, 0, 0);
	glNormal3f(0, 0, 1);
	glRectd(-0.5, -0.5, 0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
	glRotated(180, 1, 0, 0);
	glTranslated(0, 0.5, 0);
	glRotated(-90, 1, 0, 0);
	glNormal3f(0, 0, 1);
	glRectd(-0.5, -0.5, 0.5, 0.5);
	glPopMatrix();

	// YZ parallel faces
	glPushMatrix();
	glTranslated(0.5, 0, 0);
	glRotated(90, 0, 1, 0);
	glNormal3f(0, 0, 1);
	glRectd(-0.5, -0.5, 0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
	glRotated(180, 0, 0, 1);
	glTranslated(0.5, 0, 0);
	glRotated(90, 0, 1, 0);
	glNormal3f(0, 0, 1);
	glRectd(-0.5, -0.5, 0.5, 0.5);
	glPopMatrix();
}
