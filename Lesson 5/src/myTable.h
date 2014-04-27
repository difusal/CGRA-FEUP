#pragma once

#include "myUnitCube.h"

class myTable {
private:
	myUnitCube cube;
public:
	myTable(void);
	~myTable(void);

	void draw();

	double getHeight() {
		return 3.5 + 0.3 / 2;
	}
};

