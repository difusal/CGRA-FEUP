#pragma once

#include "CGFobject.h"

class MyUnitCube: public CGFobject {
public:
	MyUnitCube(void);
	~MyUnitCube(void);

	void draw(bool applyTexturePoints);
};
