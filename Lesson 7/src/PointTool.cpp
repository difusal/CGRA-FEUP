#include "PointTool.h"

void PointTool::mousePressed(int x, int y) {
	canvas->setPixel(x, y);
}

void PointTool::mouseDragged(int x, int y) {
	canvas->setPixel(x, y);
}

void PointTool::mouseReleased(int x, int y) {
}

