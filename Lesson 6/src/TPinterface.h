#ifndef TPinterface_H
#define TPinterface_H

#include "CGFinterface.h"

class TPinterface: public CGFinterface {
public:
	TPinterface();

	virtual void initGUI();
	void initLightsPanel();
	void initClockPanel();
	void initRobotPanel();
	void initOthersPanel();

	virtual void processGUI(GLUI_Control *ctrl);
	virtual void processKeyboard(unsigned char key, int x, int y);

	int robotListBoxSelectedItemID;
	int robotRadioGroupSelectedItemID;
};

#endif
