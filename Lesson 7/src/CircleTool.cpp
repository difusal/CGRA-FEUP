#include "CircleTool.h"

#include <cmath>
#include <algorithm>

void CircleTool::mousePressed(int x, int y) {
	// Reset start coordinates and active (current) coordinates
	sx = x;
	sy = y;
	currx = x;
	curry = y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw (one pixel)
	drawCircle(sx, sy, currx, curry);
}

void CircleTool::mouseDragged(int x, int y) {
	// Redraw previous circle (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawCircle(sx, sy, currx, curry);

	// Update current coordinates
	currx = x;
	curry = y;

	// Draw new circle
	drawCircle(sx, sy, currx, curry);
}

void CircleTool::mouseReleased(int x, int y) {
	// Redraw previous circle to erase it
	drawCircle(sx, sy, currx, curry);

	// Set normal mode and color to draw final circle
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final circle
	drawCircle(sx, sy, x, y);
}

int CircleTool::getRadius(int xi, int yi, int xf, int yf) {
	int dx = abs(xf - xi);
	int dy = abs(yf - yi);

	return sqrt(dy * dy + dx * dx);
}

void CircleTool::drawCircle(int xi, int yi, int xf, int yf) {
	// get radius
	int r = getRadius(xi, yi, xf, yf);

	int x = 0, y = r, p = 1 - r;
	int incE = 3, incSE = 5 - 2 * r;

	canvas->setPixel(x, y);
	while (y > x) {
		if (p < 0) {
			p = p + incE;
			incE = incE + 2;
			incSE = incSE + 2;
			x++;
		} else {
			p = p + incSE;
			incE = incE + 2;
			incSE = incSE + 4;
			x++, y--;
		}

		for (int i = 1; i >= -1; i -= 2) {
			for (int j = 1; j >= -1; j -= 2) {
				canvas->setPixel(xi + i * x, yi + j * y);
				canvas->setPixel(xi + i * y, yi + j * x);
			}
		}
	}
}
