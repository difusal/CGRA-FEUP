#include "MyCylinder.h"

#include "Utilities.h"

MyCylinder::MyCylinder(int slices, int stacks, int smooth) {
	this->slices = slices;
	this->stacks = stacks;
	this->smooth = smooth;

	alpha = 360.0 / slices;
	stackHeight = 1.0 / stacks;

	// calculating points to use on both bases and body
	pointsVec.clear();
	for (int i = 0; i < slices; i++) {
		double x = cos(degToRad(alpha * i));
		double y = sin(degToRad(alpha * i));

		pointsVec.push_back(Point2D(x, y));
	}

	// calculating normals
	normalsVec.clear();
	double x1, y1, x2 = 1, y2 = 0;
	for (int i = 0; i < slices; i++) {
		x1 = x2, y1 = y2;

		if (i == slices - 1) {
			x2 = pointsVec[0].getX();
			y2 = pointsVec[0].getY();
		} else {
			x2 = pointsVec[i + 1].getX();
			y2 = pointsVec[i + 1].getY();
		}

		double ax, ay;
		ax = (x1 + x2) / 2;
		ay = (y1 + y2) / 2;

		double nx, ny, nc;
		nc = sqrt(ax * ax + ay * ay);
		nx = ax / nc;
		ny = ay / nc;

		normalsVec.push_back(Point2D(nx, ny));
	}
}

MyCylinder::~MyCylinder() {
}

void MyCylinder::draw() {
	double x1, y1, x2, y2, z1, z2;

	// 1st base
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		x1 = pointsVec[i].getX();
		y1 = pointsVec[i].getY();

		glTexCoord2d(0.5 + x1 * 0.5, 0.5 + y1 * 0.5);
		glVertex3d(x1, y1, 1);
	}
	glEnd();

	// 2nd base
	glPushMatrix();
	glRotated(180.0, 1, 0, 0);
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		x1 = pointsVec[i].getX();
		y1 = pointsVec[i].getY();

		glVertex3d(x1, y1, 0);
	}
	glEnd();
	glPopMatrix();

	// body
	x2 = 1, y2 = 0;
	for (int i = 0; i < slices; i++) {
		x1 = x2, y1 = y2;
		z2 = 1;

		if (i == slices - 1) {
			x2 = pointsVec[0].getX();
			y2 = pointsVec[0].getY();
		} else {
			x2 = pointsVec[i + 1].getX();
			y2 = pointsVec[i + 1].getY();
		}

		// flat shading
		if (!smooth) {
			double nx = normalsVec[i].getX();
			double ny = normalsVec[i].getY();

			glNormal3d(nx, ny, 0);
		}

		for (int j = 0; j < stacks; j++) {
			z1 = z2;
			z2 -= stackHeight;

			glBegin(GL_QUADS);

			if (smooth)
				glNormal3d(x1, y1, 0);
			glVertex3d(x1, y1, z1);
			glVertex3d(x1, y1, z2);

			if (smooth)
				glNormal3d(x2, y2, 0);
			glVertex3d(x2, y2, z2);
			glVertex3d(x2, y2, z1);

			glEnd();
		}
	}
}
