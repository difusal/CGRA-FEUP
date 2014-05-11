#include "TPinterface.h"

#include <cmath>
#include "LightingScene.h"
#include "Utilities.h"

TPinterface::TPinterface() {
	testVar = 0;
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
	case 'a':
		((LightingScene*) scene)->toggleSomething();
		break;
	}
}

void TPinterface::initGUI() {
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel = addPanel("Group", 1);
	addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);

	// You could also pass a reference to a variable from the scene class, if public
	addSpinnerToPanel(varPanel, "Val 2(scene)", 2,
			&(((LightingScene*) scene)->sceneVar), 2);

}

void TPinterface::processGUI(GLUI_Control *ctrl) {
	printf("GUI control id: %d\n  ", ctrl->user_id);
	switch (ctrl->user_id) {
	case 1:
		printf("New Val 1(interface): %d\n", testVar);
		break;
	case 2:
		printf("New Val 2(scene): %d\n", ((LightingScene*) scene)->sceneVar);
		break;
	};
}

