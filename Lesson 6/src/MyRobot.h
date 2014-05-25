#pragma once

#include "CGFobject.h"

#include <vector>
#include "Point2D.h"
#include "Point3D.h"

class MyRobot: public CGFobject {
private:
	int slices, stacks;
	double alpha, stackHeight;
	bool smooth;

	std::vector<Point2D> topPointsVec;
	std::vector<std::vector<Point3D> > pointsVec, normalsVec;
public:
	MyRobot(int stacks, bool smooth);
	virtual ~MyRobot();

	void draw();
	void drawTop();
	void drawBase();
	void drawFace(int face);

	double rotation;
	double x, z;
	int wireframe;
};
