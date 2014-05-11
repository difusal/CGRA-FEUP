#include "TPinterface.h"

#include <cmath>
#include "LightingScene.h"
#include "Utilities.h"

enum IDS {
	LIGHT0, LIGHT1, LIGHT2, LIGHT3, PAUSE_BTN, RESTART_BTN
};

TPinterface::TPinterface() {
}

void TPinterface::processKeyboard(unsigned char key, int x, int y) {
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	CGFinterface::processKeyboard(key, x, y);

	MyRobot* robot = ((LightingScene*) scene)->robot;
	double moveSpeed = 0.05, rotationSpeed = 2;

	switch (key) {
	case 'i':
		// move forward
		robot->x += moveSpeed * sin(degToRad(robot->rotation + 90));
		robot->z += moveSpeed * cos(degToRad(robot->rotation + 90));
		break;
	case 'j':
		// rotate left
		robot->rotation += rotationSpeed;
		break;
	case 'k':
		// move backwards
		robot->x -= moveSpeed * sin(degToRad(robot->rotation + 90));
		robot->z -= moveSpeed * cos(degToRad(robot->rotation + 90));
		break;
	case 'l':
		// rotate right
		robot->rotation -= rotationSpeed;
		break;
	}
}

void TPinterface::initGUI() {
	initLightsPanel();
	addColumn();
	initClockPanel();
}

void TPinterface::processGUI(GLUI_Control* ctrl) {
	switch (ctrl->user_id) {
	case LIGHT0:
		((LightingScene*) scene)->light0->disable();
		if (((LightingScene*) scene)->light0IsOn)
			((LightingScene*) scene)->light0->enable();
		break;
	case LIGHT1:
		((LightingScene*) scene)->light1->disable();
		if (((LightingScene*) scene)->light1IsOn)
			((LightingScene*) scene)->light1->enable();
		break;
	case LIGHT2:
		((LightingScene*) scene)->light2->disable();
		if (((LightingScene*) scene)->light2IsOn)
			((LightingScene*) scene)->light2->enable();
		break;
	case LIGHT3:
		((LightingScene*) scene)->light3->disable();
		if (((LightingScene*) scene)->light3IsOn)
			((LightingScene*) scene)->light3->enable();
		break;
	case PAUSE_BTN:
		((LightingScene*) scene)->clock->clockIsOn = 0;
		break;
	case RESTART_BTN:
		((LightingScene*) scene)->clock->clockIsOn = 1;
		break;
	};
}

void TPinterface::initLightsPanel() {
	char* text = new char[20];

	strcpy(text, "Lights");
	GLUI_Panel* lightsPanel = addPanel(text, 1);

	strcpy(text, "Light 0");
	addCheckboxToPanel(lightsPanel, text,
			&(((LightingScene*) scene)->light0IsOn), LIGHT0);

	strcpy(text, "Light 1");
	addCheckboxToPanel(lightsPanel, text,
			&(((LightingScene*) scene)->light1IsOn), LIGHT1);

	addColumnToPanel(lightsPanel);

	strcpy(text, "Light 2");
	addCheckboxToPanel(lightsPanel, text,
			&(((LightingScene*) scene)->light2IsOn), LIGHT2);

	strcpy(text, "Light 3");
	addCheckboxToPanel(lightsPanel, text,
			&(((LightingScene*) scene)->light3IsOn), LIGHT3);
}

void TPinterface::initClockPanel() {
	char* text = new char[20];

	strcpy(text, "Clock");
	GLUI_Panel* clockPanel = addPanel(text, 1);

	strcpy(text, "Pause");
	addButtonToPanel(clockPanel, text, PAUSE_BTN);

	strcpy(text, "Resume");
	addButtonToPanel(clockPanel, text, RESTART_BTN);
}
