#include "Materials.h"

Materials::Materials() {
	// coefficients for material A
	float ambA[3] = { 0.2, 0.2, 0.2 };
	float difA[3] = { 0.6, 0.6, 0.6 };
	float specA[3] = { 0, 0.8, 0.8 };
	float shininessA = 120.f;

	// coefficients for material B
	float ambB[3] = { 0.2, 0.2, 0.2 };
	float difB[3] = { 0.6, 0.6, 0.6 };
	float specB[3] = { 0.8, 0.8, 0.8 };
	float shininessB = 120.f;

	// coefficients for material C
	float ambC[3] = { 0.3, 0.3, 0.3 };
	float difC[3] = { 0.3, 0.3, 0.3 };
	float specC[3] = { 0.2, 0.2, 0.2 };
	float shininessC = 120.f;

	// MATERIALS
	materialA = new CGFappearance(ambA, difA, specA, shininessA);
	materialB = new CGFappearance(ambB, difB, specB, shininessB);
	materialC = new CGFappearance(ambC, difC, specC, shininessC);
	materialC->setTexture("res/wall.png");
	materialC->setTextureWrap(GL_REPEAT, GL_REPEAT);

	// coefficients for table material
	float ambTable[3] = { 0.2, 0.2, 0.2 };
	float difTable[3] = { 0.6, 0.6, 0.6 };
	float specTable[3] = { 0.2, 0.2, 0.2 };
	float shininessTable = 60.f;

	// TABLE
	tableAppearance = new CGFappearance(ambTable, difTable, specTable,
			shininessTable);
	tableAppearance->setTexture("res/table.png");
	tableAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	// coefficients for slides material
	float ambSlides[3] = { 0.2, 0.2, 0.2 };
	float difSlides[3] = { 0.6, 0.6, 0.6 };
	float specSlides[3] = { 0.2, 0.2, 0.2 };
	float shininessSlides = 60.f;

	// SLIDES
	slidesAppearance = new CGFappearance(ambSlides, difSlides, specSlides,
			shininessSlides);
	slidesAppearance->setTexture("res/slides.png");
	slidesAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	// coefficients for board material
	float ambBoard[3] = { 0.4, 0.4, 0.4 };
	float difBoard[3] = { 0.4, 0.4, 0.4 };
	float specBoard[3] = { 0.8, 0.8, 0.8 };
	float shininessBoard = 128.f;

	// BOARD
	boardAppearance = new CGFappearance(ambBoard, difBoard, specBoard,
			shininessBoard);
	boardAppearance->setTexture("res/board.png");
	boardAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	// coefficients for window material
	float ambWindow[3] = { 0.4, 0.4, 0.4 };
	float difWindow[3] = { 0.4, 0.4, 0.4 };
	float specWindow[3] = { 0.8, 0.8, 0.8 };
	float shininessWindow = 128.f;

	// WINDOW
	windowAppearance = new CGFappearance(ambWindow, difWindow, specWindow,
			shininessWindow);
	windowAppearance->setTexture("res/window.png");
	windowAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	// coefficients for floor material
	float ambFloor[3] = { 0.4, 0.4, 0.4 };
	float difFloor[3] = { 0.4, 0.4, 0.4 };
	float specFloor[3] = { 0.3, 0.3, 0.3 };
	float shininessFloor = 60.f;

	// FLOOR
	floorAppearance = new CGFappearance(ambFloor, difFloor, specFloor,
			shininessFloor);
	floorAppearance->setTexture("res/floor.png");
	floorAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	// ROBOT
	robotAppearance = new CGFappearance(ambFloor, difFloor, specFloor,
			shininessFloor);
	robotAppearance->setTexture("res/basicRobot.jpg");
	robotAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	// LANDSCAPE
	landscapeAppearance = new CGFappearance(ambFloor, difFloor, specFloor,
			shininessFloor);
	landscapeAppearance->setTexture("res/bliss.jpg");
	landscapeAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);
}

Materials::~Materials() {
	delete (materialA);
	delete (materialB);
	delete (materialC);
	delete (tableAppearance);
	delete (slidesAppearance);
	delete (boardAppearance);
	delete (windowAppearance);
	delete (floorAppearance);
	delete (robotAppearance);
	delete (landscapeAppearance);
}

CGFappearance* Materials::getMaterial(MaterialsElem elem) {
	switch (elem) {
	case A:
		return materialA;
	case B:
		return materialB;
	case C:
		return materialC;
	case TABLE:
		return tableAppearance;
	case SLIDES:
		return slidesAppearance;
	case BOARD:
		return boardAppearance;
	case WINDOW:
		return windowAppearance;
	case FLOOR:
		return floorAppearance;
	case ROBOT:
		return robotAppearance;
	case LANDSCAPE:
		return landscapeAppearance;
	default:
		return NULL;
	}
}
