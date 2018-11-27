#ifndef CCUBE_H
#define CCUBE_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Camera.hpp"
//#include "Light.hpp"


class Cube: public Shape {
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat faceColor[6][3];
	GLfloat faceNormal[6][3];
	GLfloat cubeShade[6];
	GLfloat r, g, b;

public:
	Cube();	void draw();
	void drawMC();
	bool isFrontface(int faceindex, Camera camera);
	//GLfloat getShade(int faceindex, Light light);

private:
	void draw_face(int);
};

#endif
