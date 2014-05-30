#pragma once

#include "CGFcanvas.h"

class CanvasTool {
protected:
	CGFcanvas *canvas;

public:
	CanvasTool(CGFcanvas *cnv) {
		canvas = cnv;
	}

	virtual ~CanvasTool() {
	}

	virtual void mousePressed(int x, int y)=0;
	virtual void mouseDragged(int x, int y)=0;
	virtual void mouseReleased(int x, int y)=0;
};
