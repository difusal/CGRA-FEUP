#pragma once

#include <iostream>

class Point3D {
private:
	double x, y, z;

public:
	Point3D();
	Point3D(double x, double y, double z);
	Point3D(const Point3D& point);
	virtual ~Point3D();

	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);
	double getZ() const;
	void setZ(double z);

	friend std::ostream& operator<<(std::ostream& out, const Point3D& point) {
		out << "(" << point.x << ", " << point.y << ", " << point.z << ")";
		return out;
	}
};
