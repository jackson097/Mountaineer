#ifndef SPHERE_H
#define SPHERE_H

//#include <windows.h>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Shape.hpp"
#include "Image.hpp"

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
	Image *texture_image;
	GLUquadric *quad;
	Sphere(float rad, float red, float green, float blue, GLuint text, Image* image);
	~Sphere();
	void set_colour(GLfloat, GLfloat, GLfloat);
	void set_radius(GLfloat);
	void set_textureID(GLuint);
	void draw();
};

#endif
