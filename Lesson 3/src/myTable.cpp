#include "myTable.h"

myTable::myTable(void)
{
}

myTable::~myTable(void)
{
}

void myTable::draw()
{
	// pernas
	glPushMatrix();
	glTranslated(5/2, 3.5/2, 3/2);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(5/2, 3.5/2, -3/2);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-5/2, 3.5/2, -3/2);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-5/2, 3.5/2, 3/2);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	// tampo
	glPushMatrix();
	glTranslated(0, 3.5, 0);
	glScaled(5, 0.3, 3);
	cube.draw();
	glPopMatrix();
}
