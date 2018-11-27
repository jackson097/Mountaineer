/**
 *	File Matrix.cpp
 *	Description: implementation of Matrix class
 *
 */

#include "Matrix.hpp"

// mat <- identity matrix
Matrix::Matrix() {
	reset();
}

void Matrix::reset() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}
}

// multiplication  mat <- m * mat
void Matrix::matrixPreMultiply(Matrix* m) {
	GLfloat temp[4][4], sum=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += m->mat[i][k] * mat[k][j];
			}
			temp[i][j] = sum;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = temp[i][j];
		}
	}
}


// transpose  mat <- mat'
void Matrix::transpose() {
// your implementation
	GLfloat temp[4][4];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j <4; j++){
			temp[i][j] = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp[i][j];

		}
	}


}

// normalize mat
void Matrix::normalize() {
// your implementaiton
	GLfloat len = sqrt(mat[0][0]) * mat[0][0] + mat[1][0] *mat[1][0] + mat[2][0] * mat[2][0];
	mat[0][0] = mat[0][0]/len;
	mat[1][0] = mat[1][0] /len;
	mat[2][0] = mat[2][0] /len;

	mat[0][2] = mat[1][0] *mat[2][1]-mat[2][0]*mat[1][1];
	mat[1][2] = mat[2][0] * mat[0][1] - mat[0][0]*mat[2][1];
	mat[2][2] = mat[0][0] * mat[1][1] - mat[1][0]*mat[0][1];

	len = sqrt(mat[0][2]*mat[0][2] + mat[1][2]*mat[1][2] +mat[2][2]*mat[2][2]);
	mat[0][2] =mat[0][2]/len;
	mat[1][2] = mat[1][2]/len;
	mat[2][2] = mat[2][2]/len;

	mat[0][1] = mat[1][2] *mat[2][0]-mat[1][0]*mat[2][2];
	mat[1][1] = mat[2][2] * mat[0][0] -mat[2][0]*mat[0][2];
	mat[2][1] = mat[0][2] * mat[1][0] -mat[0][0]*mat[1][2];

	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;



}

// v  <- mat * v
void Matrix::multiplyVector(GLfloat *v) {
// your implementaiton
	GLint row;
	GLfloat sum = 0;
	GLint vect;
	for(vect = 0; vect<4; vect++){
		for(row = 0; row<4; row++){
			sum+= v[row] * this->mat[row][vect];
		}
		v[vect] = sum;
		sum = 0;
	}


}

// mat <- rotation matrix (rx, ry, rz, angle)
void Matrix::rotateMatrix(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
// your implementaiton
	GLfloat radianAngle = angle * 3.1415926 / 180;
	GLfloat axisVectLength = sqrt(rx*rx + ry*ry + rz*rz);
	GLfloat cosA = cos(radianAngle);
	GLfloat oneC = 1 - cosA;
	GLfloat sinA = sin(radianAngle);
	GLfloat ux = (rx) / axisVectLength;
	GLfloat uy = (ry) / axisVectLength;
	GLfloat uz = (rz) / axisVectLength;
	Matrix *m = new Matrix();


//	mat[0][0] = ux*ux*oneC + cosA;
//	mat[0][1] = ux*uy*oneC + uz*sinA;
//	mat[0][1] = ux*uz*oneC + uy*sinA;
//	mat[0][3] = 0;
//	mat[1][3] = 0;
//	mat[2][3] = 0;
//	mat[3][3] = 1;
//	mat[3][2] = 0;
//	mat[3][1] = 0;
//	mat[3][0] = 0;

	m->mat[0][0] = ux*ux*oneC + cosA;
	m->mat[0][1] = uy*ux*oneC + uz*sinA;
	m->mat[0][2] = ux*uz*oneC - uy *sinA;
	m->mat[0][3] = 0;
	m->mat[1][0] = ux*uy*oneC - uz*sinA;
	m->mat[1][1] = uy*uy*oneC + cosA;
	m->mat[1][2] = uy*uz*oneC + ux*sinA;
	m->mat[1][3] = 0;
	m->mat[2][0] = ux*uz*oneC + uy*sinA;
	m->mat[2][1] = uy*uz*oneC - ux*sinA;
	m->mat[2][2] = uz*uz*oneC + cosA;
	m->mat[2][3] = 0;
	m->mat[3][0] = 0;
	m->mat[3][1] = 0;
	m->mat[3][2] = 0;
	m->mat[3][3] = 1;
	this->matrixPreMultiply(m);
	delete m;



}

