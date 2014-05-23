#pragma once

#include "CGFobject.h"
class Plane {
public:
	Plane(void);
	Plane(int);
	~Plane(void);

	void drawWithRepeatedTexture(int xRepetitions, int yRepetitions);
	void drawWithStretchedTexture();
	void drawWithFittedTexture(double offset);
	void drawWithCenteredTexture(double xOffset, double yOffset);
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
};

