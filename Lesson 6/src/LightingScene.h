#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "MyClock.h"
#include "MyRobot.h"
#include "MyWallWithWindow.h"

class LightingScene: public CGFscene {
public:
	void init();
	void update(unsigned long sysTime);
	void display();
	~LightingScene();

	void toggleShowTables();

	bool showTables;
	int light0IsOn, light1IsOn, light2IsOn, light3IsOn;

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	CGFlight* lightWindow;

	myTable* table;
	Plane* wall;
	Plane* landscape;
	MyWallWithWindow* wallWithWindow;
	Plane* boardA;
	Plane* boardB;
	myCylinder* column;
	myLamp* lamp;
	MyClock* clock;
	MyRobot* robot;

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
};

#endif
