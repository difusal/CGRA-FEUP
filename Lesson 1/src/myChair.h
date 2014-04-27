#pragma once

#include "myUnitCube.h"

class myChair
{
private:
	int size;
	double height;
	double transl;
	double angle;

	myUnitCube cube;
public:
	myChair();
	~myChair();

	void draw();
};
