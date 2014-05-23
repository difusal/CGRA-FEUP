#pragma once

#include <iostream>

class Point2D {
	double x, y;
public:
	Point2D();
	Point2D(double x, double y);
	Point2D(const Point2D& point);
	virtual ~Point2D();

	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);

	friend std::ostream& operator<<(std::ostream& out, const Point2D& point) {
		out << "(" << point.x << ", " << point.y << ")\n";
		return out;
	}
};

