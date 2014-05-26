#include "MyRobot.h"

#include <vector>
#include "Utilities.h"

using namespace std;

MyRobot::MyRobot(int stacks, int smooth) {
	this->slices = 12;
	this->stacks = stacks;
	this->smooth = smooth;

	rotation = 135;
	x = z = 7.5;
	wireframe = 0;

	alpha = 360.0 / slices;
	stackHeight = 1.0 / stacks;

	calculateTopVertexesAndTexturePoints();
	calculateFaceVertexes();
	calculateFlatFaceNormals();
	calculateSmoothFaceNormals();
	calculateFaceTexturePoints();
}

MyRobot::~MyRobot() {
}

void MyRobot::calculateTopVertexesAndTexturePoints() {
	// clear vectors
	topVertexes.clear();
	topTexturePoints.clear();

	for (int i = 0; i < slices; i++) {
		// calculate top vertexes
		double x = 0.25 * cos(degToRad(-45 + i * alpha));
		double y = 0.25 * sin(degToRad(-45 + i * alpha));
		topVertexes.push_back(Point2D(x, y));

		// calculate top texture points
		double texX = 0.5 + x * 0.5;
		double texY = 0.5 + y * 0.5;
		topTexturePoints.push_back(Point2D(texX, texY));
	}

	// correcting texture points order
	for (int i = 0; i < (slices / 4); i++) {
		topTexturePoints.insert(topTexturePoints.begin(),
				topTexturePoints.back());
		topTexturePoints.pop_back();
	}
}

void MyRobot::calculateFaceVertexes() {
	// clear face points matrix container
	faceVertexes.clear();

	// prepare face points matrix container
	vector<Point3D> temp;
	for (int i = 0; i <= stacks; i++)
		faceVertexes.push_back(temp);

	// calculate robot face points matrix
	for (int i = 0; i <= slices / 4; i++) {
		double x = topVertexes[i].getX();
		double y = topVertexes[i].getY();
		Point3D start(x, y, 1);

		y = -0.5 + i / (slices / 4.0);
		Point3D end(0.5, y, 0);

		Point3D interpolVec = (end - start) / stacks;

		for (int j = 0; j <= stacks; j++)
			faceVertexes[j].push_back(start + j * interpolVec);
	}
}

void MyRobot::calculateFlatFaceNormals() {
	// clear flat normals container
	flatFaceNormals.clear();

	// for each stack
	for (unsigned int i = 0; i < faceVertexes.size() - 1; i++) {
		vector<Point3D> stackNormals;

		// for each slice
		for (unsigned int j = 0; j < faceVertexes[i].size() - 1; j++) {
			// get polygon points
			double x1 = faceVertexes[i][j].getX();
			double y1 = faceVertexes[i][j].getY();

			double x2 = faceVertexes[i + 1][j].getX();
			double y2 = faceVertexes[i + 1][j].getY();

			double x3 = faceVertexes[i + 1][j + 1].getX();
			double y3 = faceVertexes[i + 1][j + 1].getY();

			double x4 = faceVertexes[i][j + 1].getX();
			double y4 = faceVertexes[i][j + 1].getY();

			double z1 = faceVertexes[i][j].getZ();
			double z2 = faceVertexes[i + 1][j].getZ();

			vector<Point3D> vertexes;
			vertexes.push_back(Point3D(x1, y1, z1));
			vertexes.push_back(Point3D(x2, y2, z2));
			vertexes.push_back(Point3D(x3, y3, z2));
			vertexes.push_back(Point3D(x4, y4, z1));

			// calculate and save normal
			stackNormals.push_back(calculateSurfaceNormal(vertexes));
		}

		flatFaceNormals.push_back(stackNormals);
	}
}

void MyRobot::calculateSmoothFaceNormals() {
	// clear smooth normals container
	smoothFaceNormals.clear();

	// prepare face points matrix container
	vector<Point3D> temp;
	for (int i = 0; i <= stacks; i++)
		smoothFaceNormals.push_back(temp);

	// for each slice
	for (int i = 0; i <= slices / 4; i++) {
		double x = faceVertexes[0][i].getX();
		double y = faceVertexes[0][i].getY();

		Point3D start(normalizeVector(Point3D(x, y, 0)));
		Point3D end(0, 1, 0);
		Point3D interpolVec = (end - start) / stacks;

		// for each stack
		for (int j = 0; j <= stacks; j++) {
			Point3D normal = normalizeVector(start + j * interpolVec);
			smoothFaceNormals[j].push_back(normal);
		}
	}
}

void MyRobot::calculateFaceTexturePoints() {
	// clear face texture points matrix container
	faceTexturePoints.clear();

	// prepare face texture points matrix container
	vector<Point2D> temp1;
	vector<vector<Point2D> > temp2;
	for (int i = 0; i <= stacks; i++)
		temp2.push_back(temp1);
	for (int i = 0; i < 4; i++)
		faceTexturePoints.push_back(temp2);

	// calculate robot face texture points for each face
	for (int k = 0; k < 4; k++) {
		// getting correct face top texture points
		if (k > 0) {
			for (int i = 0; i < (slices / 4); i++) {
				topTexturePoints.push_back(topTexturePoints.front());
				topTexturePoints.erase(topTexturePoints.begin());
			}
		}

		// for each slice
		for (int i = 0; i <= slices / 4; i++) {
			Point2D start;
			start.setX(topTexturePoints[i].getX());
			start.setY(topTexturePoints[i].getY());

			Point2D end;
			switch (k) {
			case 0:
				end.setX(i / (slices / 4.0));
				end.setY(0);
				break;
			case 1:
				end.setX(1);
				end.setY(i / (slices / 4.0));
				break;
			case 2:
				end.setX((slices / 4.0 - i) / (slices / 4.0));
				end.setY(1);
				break;
			case 3:
				end.setX(0);
				end.setY((slices / 4.0 - i) / (slices / 4.0));
				break;
			}

			Point2D interpolVec = end - start;
			interpolVec /= stacks;

			// for each stack
			for (int j = 0; j <= stacks; j++)
				faceTexturePoints[k][j].push_back(start + j * interpolVec);
		}
	}
}

void MyRobot::draw() {
	if (wireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glPushMatrix();

	glTranslated(x, 0, z);
	glRotated(rotation, 0, 1, 0);
	glRotated(-90, 1, 0, 0);

	// draw top and base
	drawTop(), drawBase();

	// body
	for (int i = 0; i < 4; i++) {
		glPushMatrix();

		glRotated(i * 90.0, 0, 0, 1);
		drawFace(i);

		glPopMatrix();
	}

	glPopMatrix();

	// resetting polygon mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void MyRobot::drawTop() {
	glNormal3d(0, 0, 1);

	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		double x = topVertexes[i].getX();
		double y = topVertexes[i].getY();

		double texX = topTexturePoints[i].getX();
		double texY = topTexturePoints[i].getY();

		glTexCoord2d(texX, texY);
		glVertex3d(x, y, 1);
	}
	glEnd();
}

void MyRobot::drawBase() {
	glPushMatrix();

	glRotated(180.0, 1, 0, 0);

	glNormal3d(0, 0, 1);

	glBegin(GL_POLYGON);
	glVertex3d(-0.5, 0.5, 0);
	glVertex3d(-0.5, -0.5, 0);
	glVertex3d(0.5, -0.5, 0);
	glVertex3d(0.5, 0.5, 0);
	glEnd();

	glPopMatrix();
}

void MyRobot::drawFace(int face) {
	// for each stack
	for (unsigned int i = 0; i < faceVertexes.size() - 1; i++) {
		// for each slice
		for (unsigned int j = 0; j < faceVertexes[i].size() - 1; j++) {
			// flat shading
			if (!smooth) {
				Point3D n = flatFaceNormals[i][j];
				glNormal3d(n.getX(), n.getY(), n.getZ());
			}

			// vertexes
			double x1 = faceVertexes[i][j].getX();
			double y1 = faceVertexes[i][j].getY();

			double x2 = faceVertexes[i + 1][j].getX();
			double y2 = faceVertexes[i + 1][j].getY();

			double x3 = faceVertexes[i + 1][j + 1].getX();
			double y3 = faceVertexes[i + 1][j + 1].getY();

			double x4 = faceVertexes[i][j + 1].getX();
			double y4 = faceVertexes[i][j + 1].getY();

			double z1 = faceVertexes[i][j].getZ();
			double z2 = faceVertexes[i + 1][j].getZ();

			// texture points
			double texX1 = faceTexturePoints[face][i][j].getX();
			double texY1 = faceTexturePoints[face][i][j].getY();

			double texX2 = faceTexturePoints[face][i + 1][j].getX();
			double texY2 = faceTexturePoints[face][i + 1][j].getY();

			double texX3 = faceTexturePoints[face][i + 1][j + 1].getX();
			double texY3 = faceTexturePoints[face][i + 1][j + 1].getY();

			double texX4 = faceTexturePoints[face][i][j + 1].getX();
			double texY4 = faceTexturePoints[face][i][j + 1].getY();

			// draw polygon
			glBegin(GL_QUADS);

			if (smooth) {
				Point3D n = smoothFaceNormals[i][j];
				glNormal3d(n.getX(), n.getY(), n.getZ());
			}
			glTexCoord2d(texX1, texY1);
			glVertex3d(x1, y1, z1);

			if (smooth) {
				Point3D n = smoothFaceNormals[i + 1][j];
				glNormal3d(n.getX(), n.getY(), n.getZ());
			}
			glTexCoord2d(texX2, texY2);
			glVertex3d(x2, y2, z2);

			if (smooth) {
				Point3D n = smoothFaceNormals[i + 1][j + 1];
				glNormal3d(n.getX(), n.getY(), n.getZ());
			}
			glTexCoord2d(texX3, texY3);
			glVertex3d(x3, y3, z2);

			if (smooth) {
				Point3D n = smoothFaceNormals[i][j + 1];
				glNormal3d(n.getX(), n.getY(), n.getZ());
			}
			glTexCoord2d(texX4, texY4);
			glVertex3d(x4, y4, z1);

			glEnd();
		}
	}
}
