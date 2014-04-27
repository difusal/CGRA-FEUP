#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
#include "myDesk.h"
#include "myFloor.h"
#include <vector>

class TPscene : public CGFscene
{
private:
	int rows, columns;
	vector<myDesk> desksMatrix;
	myFloor floor;

public:
	void init();
	void display();
};

#endif