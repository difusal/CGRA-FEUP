/*
 * Point3D.cpp
 *
 *  Created on: May 23, 2014
 *      Author: henrique
 */

#include "Point3D.h"

Point3D::Point3D() {
	x = y = z = 0;
}

Point3D::Point3D(double x, double y) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3D::Point3D(const Point3D& point) {
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
}

Point3D::~Point3D() {
}

double Point3D::getX() const {
	return x;
}

void Point3D::setX(double x) {
	this->x = x;
}

double Point3D::getY() const {
	return y;
}

void Point3D::setY(double y) {
	this->y = y;
}

double Point3D::getZ() const {
	return z;
}

void Point3D::setZ(double z) {
	this->z = z;
}

