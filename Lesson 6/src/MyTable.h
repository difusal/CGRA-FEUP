#pragma once

#include "MyUnitCube.h"

const double height = 3.5 + 0.3 / 2;

class MyTable {
private:
	MyUnitCube cube;

public:
	MyTable(void);
	~MyTable(void);

	void draw();

	double getHeight() {
		return height;
	}
};

