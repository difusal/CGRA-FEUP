#ifndef LightingScene_H
#define LightingScene_H

#include "Materials.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "MyClock.h"
#include "MyRobot.h"
#include "MyWallWithWindow.h"
#include "Utilities.h"

class LightingScene: public CGFscene {
public:
	void init();
	void initLights();
	void update(unsigned long sysTime);
	void display();
	~LightingScene();

	void toggleShowTables();

	int showTables;
	int light0IsOn, light1IsOn, light2IsOn, light3IsOn;
	RobotTexureID robotTextureID;

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

	Materials* materials;
};

#endif
