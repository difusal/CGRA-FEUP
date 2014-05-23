#include "MyTable.h"

MyTable::MyTable(void) {
}

MyTable::~MyTable(void) {
}

void MyTable::draw() {
	// legs
	glPushMatrix();
	glTranslated(5 / 2, 3.5 / 2, 3 / 2);
	glScaled(0.3, 3.5, 0.3);
	cube.draw(false);
	glPopMatrix();

	glPushMatrix();
	glTranslated(5 / 2, 3.5 / 2, -3 / 2);
	glScaled(0.3, 3.5, 0.3);
	cube.draw(false);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-5 / 2, 3.5 / 2, -3 / 2);
	glScaled(0.3, 3.5, 0.3);
	cube.draw(false);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-5 / 2, 3.5 / 2, 3 / 2);
	glScaled(0.3, 3.5, 0.3);
	cube.draw(false);
	glPopMatrix();

	// tabletop
	glPushMatrix();
	glTranslated(0, 3.5, 0);
	glScaled(5, 0.3, 3);
	cube.draw(true);
	glPopMatrix();
}
