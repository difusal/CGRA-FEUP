#pragma once

#include "myChair.h"
#include "myTable.h"

class myDesk
{
private:
	double transl;
	double angle;
	myChair chair;
	myTable table;

public:
	myDesk(void);
	~myDesk(void);

	void draw();
};

