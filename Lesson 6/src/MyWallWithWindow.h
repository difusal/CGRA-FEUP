/*
 * MyWallWithWindow.h
 *
 *  Created on: May 11, 2014
 *      Author: henrique
 */

#ifndef MYWALLWITHWINDOW_H_
#define MYWALLWITHWINDOW_H_

class MyWallWithWindow {
	double width, height;
	double horMargins, verMargins;
public:
	MyWallWithWindow(double width, double height, double horMargins, double verMargins);
	virtual ~MyWallWithWindow();

	double getWidth();

	void draw();
};

#endif /* MYWALLWITHWINDOW_H_ */
