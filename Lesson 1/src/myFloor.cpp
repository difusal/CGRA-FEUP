#include "myFloor.h"

myFloor::myFloor(void)
{
	width = 5;
	length = 4;
}

myFloor::~myFloor(void)
{
}

void myFloor::draw()
{
	glPushMatrix();
	glScaled(8*length, 0.1, 6*width);
	cube.draw();
	glPopMatrix();
}
