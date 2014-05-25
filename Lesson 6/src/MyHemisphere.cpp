#include "MyHemisphere.h"
#include "Utilities.h"

MyHemisphere::MyHemisphere(int slices, int stacks, bool smooth) {
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

	// calculating hemisphere points matrix
	double x, y, z;
	double radius = 0;
	for (int j = 0; j <= stacks; j++) {
		z = 1 - (j * stackHeight);
		radius = sqrt(1 - z * z);

		std::vector<Point3D> temp;
		for (int i = 0; i < slices; i++) {
			x = cos(degToRad(alpha * i)) * radius;
			y = sin(degToRad(alpha * i)) * radius;

			// saving points
			temp.push_back(Point3D(x, y, z));
		}

		pointsVec.push_back(temp);
	}

	// calculating normals
	for (int i = 0; i < stacks; i++) {
		std::vector<Point3D> temp;

		for (int j = 0; j < slices; j++) {
			double x1, y1, x2, y2, x3, y3, x4, y4, outz, inz;

			x1 = pointsVec[i][j].getX();
			y1 = pointsVec[i][j].getY();

			x2 = pointsVec[i + 1][j].getX();
			y2 = pointsVec[i + 1][j].getY();

			if (j == slices - 1) {
				x3 = pointsVec[i + 1][0].getX();
				y3 = pointsVec[i + 1][0].getY();

				x4 = pointsVec[i][0].getX();
				y4 = pointsVec[i][0].getY();
			} else {
				x3 = pointsVec[i + 1][j + 1].getX();
				y3 = pointsVec[i + 1][j + 1].getY();

				x4 = pointsVec[i][j + 1].getX();
				y4 = pointsVec[i][j + 1].getY();
			}

			outz = pointsVec[i][j].getZ();
			inz = pointsVec[i + 1][j].getZ();

			// START calculating polygon normal
			double nx, ny, nz;
			nx = x1 + x2 + x3 + x4;
			ny = y1 + y2 + y3 + y4;
			nz = outz + inz + inz + outz;

			double normal = sqrt(nx * nx + ny * ny + nz * nz);
			// STOP calculating polygon normal

			temp.push_back(Point3D(nx / normal, ny / normal, nz / normal));
		}

		normalsVec.push_back(temp);
	}
}

void MyHemisphere::draw() {
	double x1, y1, x2, y2, x3, y3, x4, y4, outz, inz;

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
	for (int i = 0; i < stacks; i++) {
		for (int j = 0; j < slices; j++) {
			x1 = pointsVec[i][j].getX();
			y1 = pointsVec[i][j].getY();

			x2 = pointsVec[i + 1][j].getX();
			y2 = pointsVec[i + 1][j].getY();

			if (j == slices - 1) {
				x3 = pointsVec[i + 1][0].getX();
				y3 = pointsVec[i + 1][0].getY();

				x4 = pointsVec[i][0].getX();
				y4 = pointsVec[i][0].getY();
			} else {
				x3 = pointsVec[i + 1][j + 1].getX();
				y3 = pointsVec[i + 1][j + 1].getY();

				x4 = pointsVec[i][j + 1].getX();
				y4 = pointsVec[i][j + 1].getY();
			}

			outz = pointsVec[i][j].getZ();
			inz = pointsVec[i + 1][j].getZ();

			// flat shading
			if (!smooth) {
				Point3D n = normalsVec[i][j];
				glNormal3d(n.getX(), n.getY(), n.getZ());
			}

			// START drawing polyhedron
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
			// STOP drawing polyhedron
		}
	}
}
