#pragma once

#include "CanvasTool.h"

class RectTool: public CanvasTool {
public:
	RectTool(CGFcanvas *cnv) :
			CanvasTool(cnv) {
	}

	virtual ~RectTool() {

	}

	virtual void mousePressed(int x, int y);
	virtual void mouseDragged(int x, int y);
	virtual void mouseReleased(int x, int y);

	virtual void drawRect(int xi, int yi, int xf, int yf);

	int sx, sy, currx, curry;
};
