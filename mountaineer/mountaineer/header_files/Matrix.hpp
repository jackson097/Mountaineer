

#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

using namespace std;

class Matrix {
public:
	GLfloat mat[4][4];   					// This matrix is for MC
	Matrix();  								// Constructor
	void reset();  							
	void matrixPreMultiply(Matrix* m);  	// mat <- m*mat
	void multiplyVector(GLfloat* v); 		// mat*v
	void normalize();  						// mormalize mat
	void transpose();  						// mat <- mat'
	void rotateMatrix(GLfloat x, GLfloat y, GLfloat z, GLfloat angle); //mat <- Rotation(rx, ry, rz, angle)
};

#endif
