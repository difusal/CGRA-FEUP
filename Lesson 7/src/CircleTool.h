#pragma once

#include "CanvasTool.h"

class CircleTool: public CanvasTool {
public:
	CircleTool(CGFcanvas *cnv) :
			CanvasTool(cnv) {
		sx = sy = currx = curry = -1;
	}

	virtual ~CircleTool() {
	}

	virtual void mousePressed(int x, int y);
	virtual void mouseDragged(int x, int y);
	virtual void mouseReleased(int x, int y);

	virtual int getRadius(int xi, int yi, int xf, int yf);
	virtual void drawCircle(int xi, int yi, int xf, int yf);

	int sx, sy, currx, curry;
};
