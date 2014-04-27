#include "myDesk.h"


myDesk::myDesk(void)
{
	double minAngle = -20;
	double maxAngle = 20;
	angle = (rand() % (int)(maxAngle-minAngle)) + minAngle;

	double minTrans = -0.2;
	double maxTrans = 1.5;
	transl = (rand() % (int)(maxTrans-minTrans)) + minTrans;
}


myDesk::~myDesk(void)
{
}

void myDesk::draw()
{
	// applying chair random rotation and translation
	glPushMatrix();
	glTranslated(0, 0, transl);
	glRotated(angle, 0, 1, 0);

	table.draw();
	glPushMatrix();
	glTranslated(0, 0, 1.2);
	chair.draw();
	glPopMatrix();

	glPopMatrix();
}
