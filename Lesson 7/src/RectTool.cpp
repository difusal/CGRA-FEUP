#include "RectTool.h"

#include <algorithm>

void RectTool::mousePressed(int x, int y) {
	// Reset start coordinates and active (current) coordinates
	sx = x;
	sy = y;
	currx = x;
	curry = y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw (one pixel)
	drawRect(sx, sy, currx, curry);
}

void RectTool::mouseDragged(int x, int y) {
	// Redraw previous rectangle (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawRect(sx, sy, currx, curry);

	// Update current coordinates
	currx = x;
	curry = y;

	// Draw new line
	drawRect(sx, sy, currx, curry);
}

void RectTool::mouseReleased(int x, int y) {
	// Redraw previous rectangle to erase it
	drawRect(sx, sy, currx, curry);

	// Set normal mode and color to draw final rectangle
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawRect(sx, sy, x, y);
}

void RectTool::drawRect(int xi, int yi, int xf, int yf) {
	// y correction
	if (yi > yf)
		std::swap(yi, yf);

	// x correction
	if (xi > xf)
		std::swap(xi, xf);

	// horizontal borders
	for (int i = xi; i <= xf; i++) {
		canvas->setPixel(i, yi);
		canvas->setPixel(i, yf);
	}

	// vertical borders
	for (int i = yi + 1; i < yf; i++) {
		canvas->setPixel(xi, i);
		canvas->setPixel(xf, i);
	}
}
