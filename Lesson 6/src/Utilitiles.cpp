#include "Utilities.h"

#include "CGFobject.h"

using namespace std;

const double pi180 = acos(-1.0) / 180;

double degToRad(double deg) {
	return deg * pi180;
}

void drawMyRect(double x1, double y1, double x2, double y2,
		bool applyTexturePoints) {
	if (!applyTexturePoints)
		glDisable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	if (applyTexturePoints)
		glTexCoord2d(0, 0);
	glVertex3d(x1, y1, 0);

	if (applyTexturePoints)
		glTexCoord2d(1, 0);
	glVertex3d(x2, y1, 0);

	if (applyTexturePoints)
		glTexCoord2d(1, 1);
	glVertex3d(x2, y2, 0);

	if (applyTexturePoints)
		glTexCoord2d(0, 1);
	glVertex3d(x1, y2, 0);

	glEnd();

	if (!applyTexturePoints)
		glEnable(GL_TEXTURE_2D);
}

double calculateAngleBetween(Point2D u, Point2D v) {
	double num = u.getX() * v.getX() + u.getY() * v.getY();
	double denom = sqrt(u.getX() * u.getX() + u.getY() * u.getY())
			* sqrt(v.getX() * v.getX() + v.getY() * v.getY());

	return acos(num / denom);
}

Point3D normalizeVector(Point3D normal) {
	double powX = pow(normal.getX(), 2);
	double powY = pow(normal.getY(), 2);
	double powZ = pow(normal.getZ(), 2);

	double length = sqrt(powX + powY + powZ);

	return normal /= length;
}

// Newell's method
Point3D calculateSurfaceNormal(std::vector<Point3D> polygonVertexes) {
	double x = 0, y = 0, z = 0;

	for (unsigned int i = 0; i < polygonVertexes.size(); i++) {
		Point3D current = polygonVertexes[i];
		Point3D next = polygonVertexes[(i + 1) % polygonVertexes.size()];

		x += (current.getY() - next.getY()) * (current.getZ() + next.getZ());
		y += (current.getZ() - next.getZ()) * (current.getX() + next.getX());
		z += (current.getX() - next.getX()) * (current.getY() + next.getY());
	}

	return normalizeVector(Point3D(x, y, z));
}
