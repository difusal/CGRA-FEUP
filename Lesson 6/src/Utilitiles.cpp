#include "Utilities.h"
#include "CGFobject.h"

using namespace std;

const double pi180 = M_PI / 180;

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

vector<double> normalizeVector(vector<double> normal) {
	double length = sqrt(
			pow(normal[0], 2) + pow(normal[1], 2) + pow(normal[2], 2));

	normal[0] /= length;
	normal[1] /= length;
	normal[2] /= length;

	return normal;
}

// Newell's method
vector<double> calculateSurfaceNormal(vector<vector<double> > polygonVertexes) {
	vector<double> normal(3);
	int x = 0, y = 1, z = 2;

	vector<double> current;
	vector<double> next;
	for (int i = 0; i < polygonVertexes.size(); i++) {
		current = polygonVertexes[i];
		next = polygonVertexes[(i + 1) % polygonVertexes.size()];

		normal[x] += (current[y] - next[y]) * (current[z] + next[z]);
		normal[y] += (current[z] - next[z]) * (current[x] + next[x]);
		normal[z] += (current[x] - next[x]) * (current[y] + next[y]);
	}

	return normalizeVector(normal);
}
