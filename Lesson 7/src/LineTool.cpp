#include "LineTool.h"

#include <algorithm>

void LineTool::mousePressed(int x, int y) {
	// Reset start coordinates and active (current) coordinates
	sx = x;
	sy = y;
	currx = x;
	curry = y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw first line (one pixel)
	drawLine(sx, sy, currx, curry);
}

void LineTool::mouseDragged(int x, int y) {
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawLine(sx, sy, currx, curry);

	// Update current coordinates
	currx = x;
	curry = y;

	// Draw new line
	drawLine(sx, sy, currx, curry);
}

void LineTool::mouseReleased(int x, int y) {
	// Redraw previous line to erase it
	drawLine(sx, sy, currx, curry);

	// Set normal mode and color to draw fianl line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawLine(sx, sy, x, y);
}

void LineTool::drawLine(int xi, int yi, int xf, int yf) {
	int a = abs(xf - xi);
	int b = abs(yf - yi);

	bool invertXY = false;
	if (b > a) {
		std::swap(xi, yi);
		std::swap(xf, yf);
		std::swap(a, b);
		invertXY = true;
	}

	if (xf < xi)
		std::swap(xi, xf), std::swap(yi, yf);

	// do not touch this
	int inc2 = 2 * b;
	int d = inc2 - a;	// d = 2*b – a;
	int inc1 = d - a;	// inc1 = 2*(b-a);

	int x = xi, y = yi;
	for (int i = 0; i < a; i++, x++) {
		invertXY ? canvas->setPixel(y, x) : canvas->setPixel(x, y);

		d >= 0 ? yi > yf ? y-- : y++, d += inc1 : d += inc2;
	}
}
