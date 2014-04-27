#ifndef MY_SEMISPHERE
#define MY_SEMISPHERE

#include "CGFobject.h"

class mySemiSphere: public CGFobject {
private:
	int slices, stacks;
	bool smooth;
public:
	mySemiSphere(int slices, int stacks, bool smooth);

	void draw();
};

#endif
