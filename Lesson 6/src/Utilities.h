#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <cmath>
#include "Point3D.h"

enum RobotTexureID {
	BASIC, METAL, MATRIX
};

double degToRad(double deg);
void drawMyRect(double x1, double y1, double x2, double y2,
		bool applyTexturePoints);
Point3D calculateSurfaceNormal(std::vector<Point3D> polygonVertexes);

#endif
