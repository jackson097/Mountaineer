/**
 *	file: Matrix.hpp
 *	author: HBF
 *	description: header of Matrix class
 */

#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <GL/gl.h>
#include <math.h>

using namespace std;

class Matrix {
public:
	GLfloat mat[4][4];   					// this matrix is for MC
	Matrix();  								// constructor
	void reset();  								// constructor
	void matrixPreMultiply(Matrix* m);  	// mat <- m*mat
	void multiplyVector(GLfloat* v); 		// mat*v
	void normalize();  						// mormalize mat
	void transpose();  						// mat <- mat'
	void rotateMatrix(GLfloat x, GLfloat y, GLfloat z, GLfloat angle); //mat <- Rotation(rx, ry, rz, angle)
};

#endif
