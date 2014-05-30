#pragma once

#include "CanvasTool.h"

class PointTool: public CanvasTool {
public:
	PointTool(CGFcanvas *cnv) :
			CanvasTool(cnv) {
	}

	virtual ~PointTool() {

	}

	virtual void mousePressed(int x, int y);
	virtual void mouseReleased(int x, int y);
	virtual void mouseDragged(int x, int y);
};
