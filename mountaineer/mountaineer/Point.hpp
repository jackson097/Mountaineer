#ifndef CPOINT_H
#define CPOINT_H

#include <GL/glut.h>

class Point{
public:
	GLfloat x,y,z;     //the coordinates
	Point();
	Point(GLfloat xx, GLfloat yy, GLfloat zz);
	void set(GLfloat xx, GLfloat yy, GLfloat zz);
	void set(Point p);
	void build4tuple(GLfloat v[]); //v[0]=x,v[1]=y,v[2]=z,v[3]=1 for homogeneous
	void printPoint();
};

#endif
