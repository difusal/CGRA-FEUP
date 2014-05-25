#pragma once

#include "CGFobject.h"

#include <vector>
#include "Point2D.h"
#include "Point3D.h"

class MyRobot: public CGFobject {
private:
	int slices, stacks;
	double alpha, stackHeight;

	std::vector<Point2D> topVertexes, topTexturePoints;
	std::vector<std::vector<Point3D> > faceVertexes;
	std::vector<std::vector<Point3D> > flatFaceNormals, smoothFaceNormals;
	std::vector<std::vector<std::vector<Point2D> > > faceTexturePoints;

public:
	MyRobot(int stacks, int smooth);
	virtual ~MyRobot();

	void calculateTopVertexesAndTexturePoints();
	void calculateFaceVertexes();
	void calculateFlatFaceNormals();
	void calculateSmoothFaceNormals();
	void calculateFaceTexturePoints();

	void draw();
	void drawTop();
	void drawBase();
	void drawFace(int face);

	int smooth;
	double rotation;
	double x, z;
	int wireframe;
};
