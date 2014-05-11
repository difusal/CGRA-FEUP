/*
 * MyRobot.h
 *
 *  Created on: May 2, 2014
 *      Author: henrique
 */

#ifndef MYROBOT_H_
#define MYROBOT_H_

#include "CGFobject.h"

class MyRobot: public CGFobject {
private:
	int slices, stacks;
	bool smooth;
public:
	MyRobot(int stacks, bool smooth);
	void drawFace(int face);
	void draw();
	virtual ~MyRobot();

	double rotation;
	double x, z;
	int wireframe;
};

#endif /* MYROBOT_H_ */
