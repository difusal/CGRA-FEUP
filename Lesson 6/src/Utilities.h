#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <cmath>

enum RobotTexureID {
	BASIC, METAL, MATRIX
};

double degToRad(double deg);
void drawMyRect(double x1, double y1, double x2, double y2,
		bool applyTexturePoints);
std::vector<double> calculateSurfaceNormal(
		std::vector<std::vector<double> > polygonVertexes);

#endif
