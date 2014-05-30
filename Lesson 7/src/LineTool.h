#ifndef _LINETOOL_H_
#define _LINETOOL_H_

#include "CanvasTool.h"

class LineTool: public CanvasTool {
public:
	LineTool(CGFcanvas *cnv) :
			CanvasTool(cnv) {
	}
	virtual ~LineTool();

	virtual void mousePressed(int x, int y);
	virtual void mouseDragged(int x, int y);
	virtual void mouseReleased(int x, int y);

	virtual void drawLine(int xi, int yi, int xf, int yf);

	int sx, sy, currx, curry;
};

#endif
