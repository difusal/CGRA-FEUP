#pragma once

#include "Materials.h"
#include "Utilities.h"

#include "MyTable.h"
#include "Plane.h"
#include "MyCylinder.h"
#include "MyLamp.h"
#include "MyClock.h"
#include "MyRobot.h"
#include "MyWallWithWindow.h"

class LightingScene: public CGFscene {
public:
	void init();
	void initLights();

	void update(unsigned long sysTime);

	void display();
	void backgroundCameraAndAxisSetup();
	void drawSceneObjects();
	void drawFloorAndWalls();
	void drawTables();
	void drawColumn();
	void drawRobot();

	~LightingScene();

	void toggleShowTables();

	int light0IsOn, light1IsOn, light2IsOn, light3IsOn;
	RobotTexureID robotTextureID;
	int showTables;

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	CGFlight* lightWindow;

	Materials* materials;

	MyTable* table;
	Plane* wall;
	Plane* landscape;
	MyWallWithWindow* wallWithWindow;
	Plane* boardA;
	Plane* boardB;
	MyCylinder* column;
	MyLamp* lamp;
	MyClock* clock;
	MyRobot* robot;
};
