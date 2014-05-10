/*
 * MyRobot.cpp
 *
 *  Created on: May 2, 2014
 *      Author: henrique
 */

#include "MyRobot.h"

#include <vector>
#include "Utilities.h"

using namespace std;

MyRobot::MyRobot(int stacks, bool smooth) {
	this->slices = 12;
	this->stacks = stacks;
	this->smooth = smooth;
}

void MyRobot::drawFace() {
	double alpha = 360.0 / slices;
	double x1, y1, x2, y2, x3, y3, x4, y4, tx4, ty4;
	double dx12, dx43, dy12, dy43, z1, z2;
	double stackHeight;
	double texx1, texy1, texx2, texy2, texx3, texy3, texx4, texy4;
	double ttexx4, ttexy4, dtexx12, dtexy12, dtexx43, dtexy43;

	x3 = 0.5;
	y3 = -0.5;

	tx4 = 0.25 * cos(degToRad(-45));
	ty4 = 0.25 * sin(degToRad(-45));

	ttexx4 = 0.5 + 0.25 * cos(degToRad(-135)) * 0.5;
	ttexy4 = 0.5 + 0.25 * sin(degToRad(-135)) * 0.5;

	stackHeight = 1.0 / stacks;

	for (int i = 0; i < slices / 4; i++) {
		// calculating major points and major texture points
		x1 = tx4;
		y1 = ty4;
		x2 = x3;
		y2 = y3;
		x3 = 0.5;
		y3 = -0.5 + (i + 1) / (slices / 4.0);
		tx4 = x4 = 0.25 * cos(degToRad(-45 + alpha * (i + 1)));
		ty4 = y4 = 0.25 * sin(degToRad(-45 + alpha * (i + 1)));
		z2 = 1;

		texx1 = ttexx4;
		texy1 = ttexy4;
		texx2 = i * 1.0 / (slices / 4);
		texy2 = 0;
		texx3 = (i + 1) * 1.0 / (slices / 4);
		texy3 = 0;
		ttexx4 = texx4 = 0.5 + 0.25 * cos(degToRad(-135 + alpha * (i + 1))) * 0.5;
		ttexy4 = texy4 = 0.5 + 0.25 * sin(degToRad(-135 + alpha * (i + 1))) * 0.5;

		// calculating interpolation data with major points
		dx12 = (x2 - x1) / stacks;
		dy12 = (y2 - y1) / stacks;
		dx43 = (x3 - x4) / stacks;
		dy43 = (y3 - y4) / stacks;

		dtexx12 = (texx2 - texx1) / stacks;
		dtexy12 = (texy2 - texy1) / stacks;
		dtexx43 = (texx3 - texx4) / stacks;
		dtexy43 = (texy3 - texy4) / stacks;

		for (int j = 0; j < stacks; j++) {
			// calculating specific points
			x2 = x1 + dx12;
			y2 = y1 + dy12;
			x3 = x4 + dx43;
			y3 = y4 + dy43;
			z1 = z2;
			z2 -= stackHeight;

			texx2 = texx1 + dtexx12;
			texy2 = texy1 + dtexy12;
			texx3 = texx4 + dtexx43;
			texy3 = texy4 + dtexy43;

			// flat shading
			if (!smooth) {
				vector<vector<double> > vertexes;
				vector<double> temp;

				temp.push_back(x1);
				temp.push_back(y1);
				temp.push_back(z1);
				vertexes.push_back(temp);
				temp.clear();

				temp.push_back(x2);
				temp.push_back(y2);
				temp.push_back(z2);
				vertexes.push_back(temp);
				temp.clear();

				temp.push_back(x3);
				temp.push_back(y3);
				temp.push_back(z2);
				vertexes.push_back(temp);
				temp.clear();

				temp.push_back(x4);
				temp.push_back(y4);
				temp.push_back(z1);
				vertexes.push_back(temp);
				temp.clear();

				vector<double> normal = calculateSurfaceNormal(vertexes);
				glNormal3d(normal[0], normal[1], normal[2]);
			}

			glBegin(GL_QUADS);

			glTexCoord2d(texx1, texy1);
			glVertex3d(x1, y1, z1);

			glTexCoord2d(texx2, texy2);
			glVertex3d(x2, y2, z2);

			glTexCoord2d(texx3, texy3);
			glVertex3d(x3, y3, z2);

			glTexCoord2d(texx4, texy4);
			glVertex3d(x4, y4, z1);

			glEnd();

			// reusing data for next iteration
			x1 = x2;
			y1 = y2;
			x4 = x3;
			y4 = y3;

			texx1 = texx2;
			texy1 = texy2;
			texx4 = texx3;
			texy4 = texy3;
		}
	}
}

void MyRobot::draw() {
	double alpha = 360.0 / slices;
	double x1, y1;

	glPushMatrix();

	glTranslated(7.5, 0, 7.5);
	glRotated(-90, 1, 0, 0);

	// top
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		x1 = 0.25 * cos(degToRad(-45 + alpha * i));
		y1 = 0.25 * sin(degToRad(-45 + alpha * i));

		glTexCoord2d(0.5 + x1 * 0.5, 0.5 + y1 * 0.5);
		glVertex3d(x1, y1, 1);
	}
	glEnd();

	// base
	glPushMatrix();
	glRotated(180.0, 1, 0, 0);
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3d(-0.5, -0.5, 0);
	glVertex3d(0.5, -0.5, 0);
	glVertex3d(0.5, 0.5, 0);
	glVertex3d(-0.5, 0.5, 0);
	glEnd();
	glPopMatrix();

	// body
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glRotated(i * 90.0, 0, 0, 1);
		drawFace();
		glPopMatrix();
	}

	glPopMatrix();
}

MyRobot::~MyRobot() {
	// TODO Auto-generated destructor stub
}
