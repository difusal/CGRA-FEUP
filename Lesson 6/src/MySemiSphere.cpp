#include "MySemiSphere.h"
#include "Utilities.h"

MySemiSphere::MySemiSphere(int slices, int stacks, bool smooth) {
	this->slices = slices;
	this->stacks = stacks;
	this->smooth = smooth;

	alpha = 360.0 / slices;
	stackHeight = 1.0 / stacks;

	// calculating points to draw base
	basePointsVec.clear();
	for (int i = 0; i < slices; i++) {
		double x = cos(degToRad(alpha * i));
		double y = sin(degToRad(alpha * i));

		basePointsVec.push_back(Point2D(x, y));
	}
}

void MySemiSphere::draw() {
	double x1, y1, x2, y2, x3, y3, x4, y4, outz, inz;
	double outRadius, inRadius;

	// base
	glPushMatrix();
	glRotated(180.0, 1, 0, 0);
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		x1 = basePointsVec[i].getX();
		y1 = basePointsVec[i].getY();

		glVertex3d(x1, y1, 0);
	}
	glEnd();
	glPopMatrix();

	// body
	inz = 1;
	inRadius = 0;
	for (int j = 0; j < stacks; j++) {
		// updating outer and inner z
		outz = inz;
		inz = 1 - ((j + 1) * stackHeight);

		// updating outer and inner radius
		outRadius = inRadius;
		inRadius = sqrt(1 - pow((1 - (j + 1) * stackHeight), 2));

		x4 = cos(degToRad(0)) * outRadius;
		y4 = sin(degToRad(0)) * outRadius;

		x3 = cos(degToRad(0)) * inRadius;
		y3 = sin(degToRad(0)) * inRadius;

		for (int i = 0; i < slices; i++) {
			// reusing previous values
			x1 = x4;
			y1 = y4;
			x2 = x3;
			y2 = y3;

			x4 = cos(degToRad(alpha * (i + 1))) * outRadius;
			y4 = sin(degToRad(alpha * (i + 1))) * outRadius;

			x3 = cos(degToRad(alpha * (i + 1))) * inRadius;
			y3 = sin(degToRad(alpha * (i + 1))) * inRadius;

			// flat shading
			if (!smooth) {
				double nx, ny, nz;
				nx = x1 + x2 + x3 + x4;
				ny = y1 + y2 + y3 + y4;
				nz = outz + inz + inz + outz;

				double normal = sqrt(nx * nx + ny * ny + nz * nz);

				glNormal3d(nx / normal, ny / normal, nz / normal);
			}

			// drawing polygon
			glBegin(GL_QUADS);

			if (smooth)
				glNormal3d(x1, y1, outz);
			glVertex3d(x1, y1, outz);

			if (smooth)
				glNormal3d(x2, y2, inz);
			glVertex3d(x2, y2, inz);

			if (smooth)
				glNormal3d(x3, y3, inz);
			glVertex3d(x3, y3, inz);

			if (smooth)
				glNormal3d(x4, y4, outz);
			glVertex3d(x4, y4, outz);

			glEnd();
		}
	}
}
