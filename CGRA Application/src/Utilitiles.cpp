#include "Utilities.h"
#include "CGFobject.h"

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
