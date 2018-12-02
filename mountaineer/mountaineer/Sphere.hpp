#ifndef SPHERE_H
#define SPHERE_H

#include <windows.h>
#include <GL/glut.h>
#include "Shape.hpp"

class Sphere: public Shape {
public:
	enum RenderMode {
		MODE_WIRE = 0,
		MODE_SOLID,
		MODE_GLSL_SOLID,
		MODE_TEXTURE
	};

	RenderMode mode;
	GLfloat radius;
	GLfloat r, g, b;
	GLint splices, stacks;
	GLuint textureID;
	GLUquadric *quad;
	Sphere();
	~Sphere();
	void set_colour(GLfloat, GLfloat, GLfloat);
	void set_radius(GLfloat);
	void draw();
};

#endif
