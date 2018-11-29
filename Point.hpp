#ifndef CPOINT_H
#define CPOINT_H

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


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
