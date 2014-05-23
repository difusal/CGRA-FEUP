#ifndef MY_SEMISPHERE
#define MY_SEMISPHERE

#include "CGFobject.h"

#include <vector>
#include "Point2D.h"
#include "Point3D.h"

class MySemiSphere: public CGFobject {
private:
	int slices, stacks;
	double alpha, stackHeight;
	bool smooth;

	std::vector<Point2D> basePointsVec;
	std::vector<std::vector<Point3D> > pointsVec;
public:
	MySemiSphere(int slices, int stacks, bool smooth);

	void draw();
};

#endif
