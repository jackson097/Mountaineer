
#ifndef CCAMERA_H
#define CCAMERA_H

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Point.hpp"
#include "Vector.hpp"

class Camera {
 public:
	Point eye; 			//camera position
	Point ref; 			//look at point
	Vector viewup; 		//view up vector
	GLfloat aspect, viewAngle, nearDist, farDist;
	Vector viewNorm;

	Camera();
	void set(Point Eye, Point look, Vector up);
	void set(float ex, float ey, float ez, float lx, float ly, float lz, float upx, float upy, float upz);
	void printCamera(void);
	void setDefaultCamera();
	void setRef(float lx, float ly, float lz);
	void setViewNorm();
	void rotate(GLfloat rx, GLfloat rz, GLfloat ry, GLfloat angle);
	void translate(GLfloat tx, GLfloat ty, GLfloat tz);
	void setViewVolume(float viewAngle, float aspect, float Near, float Far);
	void setAspect(float aspect);

	/* another set of transforms*/
	void roll(float angle);
	void pitch(float angle);
	void yaw(float angle);
	void slide(double du, double dv, double dn);

	/*  */
	void setProjectionMatrix();

};
#endif


