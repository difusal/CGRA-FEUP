#include "LightingScene.h"

#include <math.h>
#include "CGFaxis.h"
#include "CGFapplication.h"

float pi = acos(-1.0);
float deg2rad = pi / 180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// lights positions
float light0_pos[4] = { 4, 6.0, 1.0, 1.0 };
float light1_pos[4] = { 10.5, 6.0, 1.0, 1.0 };
float light2_pos[4] = { 10.5, 6.0, 5.0, 1.0 };
float light3_pos[4] = { 4, 6.0, 5.0, 1.0 };
float lightWindow_pos[4] = { 0, 4.0, 7.5, 1.0 };

// global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4] = { 0.2, 0.2, 0.2, 1.0 };

// number of board divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

float ambientNull[4] = { 0, 0, 0, 1 };
float yellow[4] = { 1, 1, 0, 1 };

void LightingScene::initLights() {
	// enables lighting computations
	glEnable(GL_LIGHTING);

	// sets up some lighting parameters, computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	// define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientNull);

	// declares and enables lights, with null ambient component
	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setSpecular(yellow);
	light0->setAmbient(ambientNull);
	light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	light1->enable();

	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(1);
	light2->setKl(0);
	light2->setKq(0);
	light2->enable();

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setKc(1);
	light3->setKl(0);
	light3->setKq(0);
	light3->enable();

	lightWindow = new CGFlight(GL_LIGHT4, lightWindow_pos);
	lightWindow->setAmbient(ambientNull);
	lightWindow->setKc(1);
	lightWindow->setKl(0);
	lightWindow->setKq(0);
	lightWindow->enable();

	light0IsOn = light1IsOn = light2IsOn = light3IsOn = 1;
}

void LightingScene::init() {
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	initLights();
	materials = new Materials();

	// scene elements
	table = new myTable();
	wall = new Plane();
	landscape = new Plane();
	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);
	column = new myCylinder(30, 30, true);
	lamp = new myLamp();
	clock = new MyClock();
	robot = new MyRobot(5, false);
	wallWithWindow = new MyWallWithWindow(15, 8, 4, 2);

	showTables = 1;
	robotTextureID = BASIC;
	setUpdatePeriod(100);
}

void LightingScene::update(unsigned long sysTime) {
	clock->update(sysTime);
}

void LightingScene::display() {
	// ---- BEGIN Background, camera and axis setup
	// Clear image and depth buffer every time we update the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	light0->update();
	light1->update();
	light2->update();
	light3->update();
	lightWindow->update();

	// Draw axis
	axis.draw();
	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section
	if (showTables) {
		// first Table
		glPushMatrix();
		glTranslated(5, 0, 8);
		materials->getMaterial(TABLE)->apply();
		table->draw();
		glPopMatrix();

		// second Table
		glPushMatrix();
		glTranslated(12, 0, 8);
		table->draw();
		glPopMatrix();

		// lamp
		glPushMatrix();
		glTranslated(3.5, table->getHeight(), 7.5);
		lamp->draw();
		glPopMatrix();
	}

	//Floor
	glPushMatrix();
	glTranslated(7.5, 0, 7.5);
	glScaled(15, 0.2, 15);
	materials->getMaterial(FLOOR)->apply();
	wall->drawWithRepeatedTexture(10, 12);
	glPopMatrix();

	// landscape
	glPushMatrix();
	glTranslated(-2, 4, 7.5);
	glRotated(90.0, 1, 0, 0);
	glRotated(-90.0, 0, 0, 1);
	glScaled(15, 0.2, 8);
	materials->getMaterial(LANDSCAPE)->apply();
	landscape->drawWithStretchedTexture();
	glPopMatrix();

	//LeftWall
	glPushMatrix();
	glTranslated(0, 0, wallWithWindow->getWidth());
	glRotated(90.0, 0, 1, 0);
	materials->getMaterial(WINDOW)->apply();
	wallWithWindow->draw();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
	glTranslated(7.5, 4, 0);
	glRotated(90.0, 1, 0, 0);
	glScaled(15, 0.2, 8);
	materials->getMaterial(C)->apply();
	wall->drawWithStretchedTexture();
	glPopMatrix();

	// Board A
	glPushMatrix();
	glTranslated(4, 4, 0.2);
	glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	glRotated(90.0, 1, 0, 0);
	materials->getMaterial(SLIDES)->apply();
	boardA->drawWithStretchedTexture();
	glPopMatrix();

	// Board B
	glPushMatrix();
	glTranslated(10.5, 4, 0.2);
	glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	glRotated(90.0, 1, 0, 0);
	materials->getMaterial(BOARD)->apply();
	int textureWidth, textureHeight;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &textureWidth);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT,
			&textureHeight);
	double offset = BOARD_HEIGHT
			- 1.0 * BOARD_WIDTH * textureHeight / textureWidth - 1;
	boardB->drawWithFittedTexture(offset);
	glPopMatrix();

	// Column
	glPushMatrix();
	glTranslated(1, 0, 14);
	glScaled(1, 8, 1);
	glRotated(-90, 1, 0, 0);
	column->draw();
	glPopMatrix();

	// Clock
	glPushMatrix();
	glTranslated(7.5, 7, 0);
	glScaled(1, 1, 0.5);
	clock->draw();
	glPopMatrix();

	// Robot
	switch (robotTextureID) {
	case BASIC:
		materials->getMaterial(ROBOT)->setTexture("res/basicRobot.jpg");
		break;
	case METAL:
		materials->getMaterial(ROBOT)->setTexture("res/metalRobot.jpg");
		break;
	case MATRIX:
		materials->getMaterial(ROBOT)->setTexture("res/matrixRobot.jpg");
		break;
	}
	materials->getMaterial(ROBOT)->apply();
	robot->draw();
	// ---- END Primitive drawing section

	// double-buffering
	glutSwapBuffers();
}

LightingScene::~LightingScene() {
	delete (light0);
	delete (light1);
	delete (light2);
	delete (light3);
	delete (lightWindow);

	delete (table);
	delete (wall);
	delete (landscape);
	delete (wallWithWindow);
	delete (boardA);
	delete (boardB);
	delete (column);
	delete (lamp);
	delete (clock);
	delete (robot);

	delete (materials);
}

void LightingScene::toggleShowTables() {
	showTables = !showTables;
}
