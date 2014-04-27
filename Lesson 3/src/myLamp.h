#ifndef MY_LAMP
#define MY_LAMP

#include "CGFobject.h"

class myLamp: public CGFobject {
private:
	int slices, stacks;
	bool smooth;
public:
	myLamp(int slices, int stacks, bool smooth);

	void draw();
};

#endif
