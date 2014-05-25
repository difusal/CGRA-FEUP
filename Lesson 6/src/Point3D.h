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

	Point3D& operator=(const Point3D &point) {
		if (this == &point)
			return *this;

		x = point.x;
		y = point.y;
		z = point.z;

		return *this;
	}

	friend Point3D operator+(Point3D start, Point3D vec) {
		double x, y, z;

		x = start.x + vec.x;
		y = start.y + vec.y;
		z = start.z + vec.z;

		return Point3D(x, y, z);
	}

	friend Point3D operator-(Point3D end, Point3D start) {
		double x, y, z;

		x = end.x - start.x;
		y = end.y - start.y;
		z = end.z - start.z;

		return Point3D(x, y, z);
	}

	friend Point3D operator*(double n, Point3D vec) {
		double x, y, z;

		x = n * vec.x;
		y = n * vec.y;
		z = n * vec.z;

		return Point3D(x, y, z);
	}

	friend Point3D operator/(Point3D vec, double n) {
		double x, y, z;

		x = vec.x / n;
		y = vec.y / n;
		z = vec.z / n;

		return Point3D(x, y, z);
	}

	Point3D& operator/=(double n) {
		this->x /= n;
		this->y /= n;
		this->z /= n;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const Point3D& point) {
		out << "(" << point.x << ", " << point.y << ", " << point.z << ")";
		return out;
	}
};
