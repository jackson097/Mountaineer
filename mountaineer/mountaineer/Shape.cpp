#include "Shape.hpp"
#include <stdlib.h>

Shape::Shape() {
	reset();
}

Shape::~Shape() { };

void Shape::reset() {
    mc.reset();
	s = 1;
};

Matrix Shape::getMC() {
	return  mc;
};

void Shape::translate(GLfloat tx, GLfloat ty, GLfloat tz) {
	mc.mat[0][3] += tx;
	mc.mat[1][3] += ty;
	mc.mat[2][3] += tz;
	mc.mat[3][3] = 1;

}


void Shape::scaleChange(GLfloat x) {
	s += x;
}

/**
 * Shape::ctm_multiply() multiply this matrix to openGL current matrix
 */
void Shape::ctmMultiply() {
	mc.transpose();
	glMultMatrixf(&mc.mat[0][0]);
	mc.transpose();

}

void Shape::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {

	Matrix m;
	m.rotateMatrix(rx,ry,rz,angle);

	mc.matrixPreMultiply(&m);
}

void Shape::rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
// your implementation
	GLfloat x0,y0,z0;
	x0 = mc.mat[0][3];
	y0 = mc.mat[1][3];
	z0 = mc.mat[2][3];
	rotate(rx,ry,rz,angle);
	mc.mat[0][3] = x0;
	mc.mat[1][3] = y0;
	mc.mat[2][3] = z0;
}

void Shape::rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
// your implementation
	Matrix m;
	m.rotateMatrix(rx,ry,rz, angle);
	GLfloat v[4];
	v[0] = mc.mat[0][3];
	v[1] = mc.mat[1][3];
	v[2] = mc.mat[2][3];
	v[3] = mc.mat[3][3];
	m.multiplyVector(v);
	mc.mat[0][3] = v[0];
	mc.mat[1][3] = v[1];
	mc.mat[2][3] = v[2];
	mc.mat[3][3] = v[3];
	//delete m;

}
void Shape::rotateRelative(GLfloat x0, GLfloat y0, GLfloat z0, GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	Matrix m; m.rotateMatrix(rx, ry, rz, angle * 1);
	GLfloat v[4]; v[0] = mc.mat[0][3]-x0; v[1] = mc.mat[1][3]-y0;
	v[2] = mc.mat[2][3]-z0; v[3] = 1;
	m.multiplyVector(v);
	mc.mat[0][3] = v[0]+x0;
	mc.mat[1][3] = v[1]+y0;
	mc.mat[2][3] = v[2]+z0;
	mc.mat[3][3] = 1;
}
int Shape::checkCollision(Shape *obstacle){
	//		printf("p:(%.1f, %.1f)", x, y);
	//		printf("o1: (%.1f, %.1f)", x1, y1);

	if(mc.mat[0][3] - 1.0 <= obstacle->mc.mat[0][3] && mc.mat[0][3] + 1.0 >= obstacle->mc.mat[0][3]){
		if(mc.mat[1][3] - 1.0 <= obstacle->mc.mat[1][3] && mc.mat[1][3] + 1.0 >= obstacle->mc.mat[1][3]){
			return 1;
		}
	}

	return 0;
}

GLfloat Shape::getX(){
	return mc.mat[0][3];
}
GLfloat Shape::getY(){
	return mc.mat[1][3];
}

int Shape::outOfBounds(){
	return mc.mat[1][3] < -5;
}
void Shape::randomX(){
	GLfloat offset = rand() % 6 -3 ;

		mc.mat[0][3] = offset;

}

void Shape::randomY(){
	GLfloat offset = rand() %3;
	GLfloat flip = rand()%1;
	if(flip > 0.5){
		mc.mat[1][3] += offset;
	}else{
		mc.mat[1][3] -= offset;
	}

}
void Shape::stayInBound(){
	if(mc.mat[0][3] > 4){
		mc.mat[0][3] = 4;
	}else if(mc.mat[0][3] < -5){
		mc.mat[0][3] = -5;
	}
	if(mc.mat[1][3] > 3){
		mc.mat[1][3] = 3;
	}else if(mc.mat[1][3] < -2){
		mc.mat[1][3] = -2;
	}
}


