#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad = pi / 180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = { 4, 6.0, 1.0, 1.0 };
float light1_pos[4] = { 10.5, 6.0, 1.0, 1.0 };

float light2_pos[4] = { 10.5, 6.0, 5.0, 1.0 };
float light3_pos[4] = { 4, 6.0, 5.0, 1.0 };

float lightWindow_pos[4] = { 0, 4.0, 7.5, 1.0 };

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4] = { 0.2, 0.2, 0.2, 1.0 };

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients4 for material A
float ambA[3] = { 0.2, 0.2, 0.2 };
float difA[3] = { 0.6, 0.6, 0.6 };
//float specA[3] = {0.2, 0.2, 0.2};
float specA[3] = { 0, 0.8, 0.8 };
//float shininessA = 10.f;
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = { 0.2, 0.2, 0.2 };
float difB[3] = { 0.6, 0.6, 0.6 };
float specB[3] = { 0.8, 0.8, 0.8 };
float shininessB = 120.f;

// Coefficients for material C
float ambC[3] = { 0.3, 0.3, 0.3 };
float difC[3] = { 0.3, 0.3, 0.3 };
float specC[3] = { 0.2, 0.2, 0.2 };
float shininessC = 120.f;

// Coefficients for table material
float ambTable[3] = { 0.2, 0.2, 0.2 };
float difTable[3] = { 0.6, 0.6, 0.6 };
float specTable[3] = { 0.2, 0.2, 0.2 };
float shininessTable = 60.f;

// Coefficients for slides material
float ambSlides[3] = { 0.2, 0.2, 0.2 };
float difSlides[3] = { 0.6, 0.6, 0.6 };
float specSlides[3] = { 0.2, 0.2, 0.2 };
float shininessSlides = 60.f;

// Coefficients for board material
float ambBoard[3] = { 0.4, 0.4, 0.4 };
float difBoard[3] = { 0.4, 0.4, 0.4 };
float specBoard[3] = { 0.8, 0.8, 0.8 };
float shininessBoard = 128.f;

// Coefficients for window material
float ambWindow[3] = { 0.4, 0.4, 0.4 };
float difWindow[3] = { 0.4, 0.4, 0.4 };
float specWindow[3] = { 0.8, 0.8, 0.8 };
float shininessWindow = 128.f;

// Coefficients for floor material
float ambFloor[3] = { 0.4, 0.4, 0.4 };
float difFloor[3] = { 0.4, 0.4, 0.4 };
float specFloor[3] = { 0.3, 0.3, 0.3 };
float shininessFloor = 60.f;

float ambientNull[4] = { 0, 0, 0, 1 };
float yellow[4] = { 1, 1, 0, 1 };

void LightingScene::init() {
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	// Define ambient light (do not confuse with ambient component of individual lights)
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientNull);

	showTables = true;

	// Declares and enables lights, with null ambient component
	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setSpecular(yellow);
	light0->setAmbient(ambientNull);
	//light0->disable();
	light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	//light1->disable();
	light1->enable();

	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(1);
	light2->setKl(0);
	light2->setKq(0);
	//light2->disable();
	light2->enable();

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setKc(1);
	light3->setKl(0);
	light3->setKq(0);
	//light3->disable();
	light3->enable();

	lightWindow = new CGFlight(GL_LIGHT4, lightWindow_pos);
	lightWindow->setAmbient(ambientNull);
	lightWindow->setKc(1);
	lightWindow->setKl(0);
	lightWindow->setKq(0);
	//lightWindow->disable();
	lightWindow->enable();

	// Uncomment below to enable normalization of lighting normal vectors
	glEnable(GL_NORMALIZE);

	//Declares scene elements
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

	// Declares materials
	materialA = new CGFappearance(ambA, difA, specA, shininessA);
	materialB = new CGFappearance(ambB, difB, specB, shininessB);
	materialC = new CGFappearance(ambC, difC, specC, shininessC);

	// table material
	tableAppearance = new CGFappearance(ambTable, difTable, specTable,
			shininessTable);
	tableAppearance->setTexture("res/table.png");
	tableAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	// slides material
	slidesAppearance = new CGFappearance(ambSlides, difSlides, specSlides,
			shininessSlides);
	slidesAppearance->setTexture("res/slides.png");
	slidesAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	// board material
	boardAppearance = new CGFappearance(ambBoard, difBoard, specBoard,
			shininessBoard);
	boardAppearance->setTexture("res/board.png");
	boardAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	// window material
	windowAppearance = new CGFappearance(ambWindow, difWindow, specWindow,
			shininessWindow);
	windowAppearance->setTexture("res/window.png");
	windowAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	// floor material
	floorAppearance = new CGFappearance(ambFloor, difFloor, specFloor,
			shininessFloor);
	floorAppearance->setTexture("res/floor.png");
	floorAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	// robot material
	robotAppearance = new CGFappearance(ambFloor, difFloor, specFloor,
			shininessFloor);
	robotAppearance->setTexture("res/robot1.jpg");
	robotAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	// landscape material
	landscapeAppearance = new CGFappearance(ambFloor, difFloor, specFloor,
			shininessFloor);
	landscapeAppearance->setTexture("res/bliss.jpg");
	landscapeAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	// defines shade model
	glShadeModel(GL_SMOOTH);

	setUpdatePeriod(100);

	sceneVar = 0;
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

	// light0->draw(); light1->draw(); light2->draw(); light3->draw();
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
		tableAppearance->apply();
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
	floorAppearance->apply();
	wall->drawWithRepeatedTexture(10, 12);
	glPopMatrix();

	// landscape
	glPushMatrix();
	glTranslated(-2, 4, 7.5);
	glRotated(90.0, 1, 0, 0);
	glRotated(-90.0, 0, 0, 1);
	glScaled(15, 0.2, 8);
	landscapeAppearance->apply();
	landscape->drawWithStretchedTexture();
	glPopMatrix();

	//LeftWall
	glPushMatrix();
	glTranslated(0, 0, wallWithWindow->getWidth());
	glRotated(90.0, 0, 1, 0);
	windowAppearance->apply();
	wallWithWindow->draw();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
	glTranslated(7.5, 4, 0);
	glRotated(90.0, 1, 0, 0);
	glScaled(15, 0.2, 8);
	materialC->apply();
	wall->drawWithStretchedTexture();
	glPopMatrix();

	// Board A
	glPushMatrix();
	glTranslated(4, 4, 0.2);
	glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	glRotated(90.0, 1, 0, 0);
	slidesAppearance->apply();
	boardA->drawWithStretchedTexture();
	glPopMatrix();

	// Board B
	glPushMatrix();
	glTranslated(10.5, 4, 0.2);
	glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	glRotated(90.0, 1, 0, 0);
	boardAppearance->apply();
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
	robotAppearance->apply();
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

	delete (table);
	delete (wall);
	delete (boardA);
	delete (boardB);

	delete (column);
	delete (lamp);
	delete (robot);

	delete (materialA);
	delete (materialB);
	delete (materialC);
	delete (tableAppearance);
	delete (slidesAppearance);
	delete (boardAppearance);
}

void LightingScene::toggleSomething() {
	showTables = !showTables;
}
