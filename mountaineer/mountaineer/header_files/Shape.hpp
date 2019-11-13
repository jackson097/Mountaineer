/**
 *	file Shape.hpp
 *	description: header of Matrix class
 *
 */

#ifndef CSHAPE_H
#define CSHAPE_H

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.hpp"

using namespace std;

/**
 * Shape class the common class that will be inherited model object class
 */
class Shape {
protected:
	Matrix mc; // the Model coordinate system (X, Y, Z, 0) in WC, represent the position of the object in WC
	GLfloat s; // scale factor

public:
	Shape();           // constructor
	virtual ~Shape();  // destructor
	Matrix getMC();    // Matrix
	void ctmMultiply();    // function to do the CTM * MC
	void scaleChange(GLfloat x); // to change the scale factor
	void translate(GLfloat tx, GLfloat ty, GLfloat tz); //translate the MC origin
	void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);      // rotate object in WC
	void rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);// just rotate the origin of object in WC
	void rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);    // to rotate in MC
	void reset();   // a function that resets the shape transformation matrix
	virtual void draw() = 0; // draw function must be overwritten
	void rotateRelative(GLfloat x0, GLfloat y0, GLfloat z0, GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	int checkCollision( Shape *obstacle);
	GLfloat getX();
	GLfloat getY();
	int outOfBounds();
	void randomX();
	void randomY();
	void stayInBound();
};

#endif
