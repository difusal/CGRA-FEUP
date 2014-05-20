#pragma once

#include "myUnitCube.h"

const double height = 3.5 + 0.3 / 2;

class myTable {
private:
	myUnitCube cube;

public:
	myTable(void);
	~myTable(void);

	void draw();

	double getHeight() {
		return height;
	}
};

