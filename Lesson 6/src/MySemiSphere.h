#ifndef MY_SEMISPHERE
#define MY_SEMISPHERE

#include "CGFobject.h"

class MySemiSphere: public CGFobject {
private:
	int slices, stacks;
	bool smooth;
public:
	MySemiSphere(int slices, int stacks, bool smooth);

	void draw();
};

#endif
