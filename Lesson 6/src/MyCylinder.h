#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGFobject.h"

#include <vector>
#include "Point2D.h"

class MyCylinder: public CGFobject {
private:
	int slices, stacks;
	double alpha, stackHeight;
	std::vector<Point2D> pointsVec, normalsVec;
public:
	MyCylinder(int slices, int stacks, int smooth);
	virtual ~MyCylinder();

	void draw();

	int smooth;
};

#endif
