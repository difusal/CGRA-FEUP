/*
 * MyWallWithWindow.cpp
 *
 *  Created on: May 11, 2014
 *      Author: henrique
 */

#include "MyWallWithWindow.h"
#include "CGFobject.h"

using namespace std;

MyWallWithWindow::MyWallWithWindow(double width, double height,
		double horMargins, double verMargins) {
	this->width = width;
	this->height = height;
	this->horMargins = horMargins;
	this->verMargins = verMargins;
}

MyWallWithWindow::~MyWallWithWindow() {
}

double MyWallWithWindow::getWidth() {
	return width;
}

void MyWallWithWindow::draw() {
	glNormal3d(0, 0, 1);

	double topAndBottomHorBorders = 0.485;
	double leftAndRightVerBorders = -0.15;

	// bottom border
	glBegin(GL_QUADS);
	glTexCoord2d(-topAndBottomHorBorders, -0.4);
	glVertex3d(0, 0, 0);
	glTexCoord2d(1 + topAndBottomHorBorders, -0.4);
	glVertex3d(width, 0, 0);
	glTexCoord2d(1 + topAndBottomHorBorders, 0.06);
	glVertex3d(width, verMargins, 0);
	glTexCoord2d(-topAndBottomHorBorders, 0.06);
	glVertex3d(0, verMargins, 0);
	glEnd();

	// left border
	glBegin(GL_QUADS);
	glTexCoord2d(-0.5, -leftAndRightVerBorders);
	glVertex3d(0, verMargins, 0);
	glTexCoord2d(0.04, -leftAndRightVerBorders);
	glVertex3d(horMargins, verMargins, 0);
	glTexCoord2d(0.04, 1 + leftAndRightVerBorders);
	glVertex3d(horMargins, height - verMargins, 0);
	glTexCoord2d(-0.5, 1 + leftAndRightVerBorders);
	glVertex3d(0, height - verMargins, 0);
	glEnd();

	// right border
	glBegin(GL_QUADS);
	glTexCoord2d(1 - 0.04, -leftAndRightVerBorders);
	glVertex3d(width - horMargins, verMargins, 0);
	glTexCoord2d(1 + 0.5, -leftAndRightVerBorders);
	glVertex3d(width, verMargins, 0);
	glTexCoord2d(1 + 0.5, 1 + leftAndRightVerBorders);
	glVertex3d(width, height - verMargins, 0);
	glTexCoord2d(1 - 0.04, 1 + leftAndRightVerBorders);
	glVertex3d(width - horMargins, height - verMargins, 0);
	glEnd();

	// top border
	glBegin(GL_QUADS);
	glTexCoord2d(-topAndBottomHorBorders, 1 - 0.06);
	glVertex3d(0, height - verMargins, 0);
	glTexCoord2d(1 + topAndBottomHorBorders, 1 - 0.06);
	glVertex3d(width, height - verMargins, 0);
	glTexCoord2d(1 + topAndBottomHorBorders, 1 + 0.4);
	glVertex3d(width, height, 0);
	glTexCoord2d(-topAndBottomHorBorders, 1 + 0.4);
	glVertex3d(0, height, 0);
	glEnd();
}
