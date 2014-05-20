#ifndef MATERIALS_H_
#define MATERIALS_H_

#include "CGFscene.h"
#include "CGFappearance.h"

enum MaterialsElem {
	A, B, C, TABLE, SLIDES, BOARD, WINDOW, FLOOR, ROBOT, LANDSCAPE
};

class Materials {
private:
	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* materialC;
	CGFappearance* tableAppearance;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;
	CGFappearance* robotAppearance;
	CGFappearance* landscapeAppearance;

public:
	Materials();
	virtual ~Materials();

	CGFappearance* getMaterial(MaterialsElem elem);
};

#endif
