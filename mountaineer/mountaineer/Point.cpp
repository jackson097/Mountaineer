#include <stdio.h>
#include "Point.hpp"

Point::Point(){
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Point::Point(GLfloat xx, GLfloat yy, GLfloat zz){
	x = xx;
	y = yy;
	z = zz;
}

void Point::set(GLfloat xx, GLfloat yy, GLfloat zz){
	x = xx;
	y = yy;
	z = zz;
}

void Point::set(Point p){
	x = p.x;
	y = p.y;
	z = p.z;
}

void Point::build4tuple(float v[]){
	v[0] = x; v[1] = y; v[2] = z; v[3] = 1.0f;
}

void Point::printPoint(){
	printf("(x:%f, y:%f, z:%f)\n",x,y,z);
}
