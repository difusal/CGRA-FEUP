#include "TPscene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#include "CGFappearance.h"
CGFappearance *mat1;

void TPscene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);  // Define ambient light

	// Declares and enables a light
	float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
	CGFlight* light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->enable();

	// Defines a default normal
	glNormal3f(0,0,1);

	// defining number of rows and columns
	rows = 5;
	columns = 4;

	// creating desks matrix
	//desksMatrix = vector<myDesk>(rows*columns, myDesk());
	for(int i = 0; i < rows*columns; i++)
		desksMatrix.push_back(myDesk());
}

void TPscene::display() 
{
	// ---- BEGIN Background, camera and axis setup
	// Clear image and depth buffer every time we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw axis
	axis.draw();
	// ---- END Background, camera and axis setup

	// drawing floor
	glPushMatrix();
	glTranslated(8*columns/2, 0, 6*rows/2);
	floor.draw();
	glPopMatrix();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			glPushMatrix();
			glTranslated(8/2 + 8*j, 0, 6/2 + 6*i);
			desksMatrix[i + columns*j].draw();
			glPopMatrix();
		}
	}

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}
