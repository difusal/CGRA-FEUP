#pragma once

#include "myUnitCube.h"

class myFloor
{
private:
	int length, width;
	myUnitCube cube;
public:
	myFloor(void);
	~myFloor(void);

	void draw();
};

