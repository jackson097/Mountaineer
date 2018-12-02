#include "Sphere.hpp"
Sphere::Sphere(float rad, float red,  float green, float blue) {
	radius = rad;
	mode = MODE_WIRE;
	textureID = 0;
	splices = 15;
	stacks = 15;
	quad = gluNewQuadric();
	r = red;
	g = green;
	b = blue;
}


Sphere::~Sphere() {
	gluDeleteQuadric(quad);
}

void Sphere::set_colour(GLfloat red, GLfloat green, GLfloat blue){
	r = red;
	g = green;
	b = blue;
}

void Sphere::set_radius(GLfloat rad){
	radius = rad;
}

void Sphere::draw() {

	glPushMatrix();
	this->ctmMultiply();
	glColor3f(r, g, b);
	glBindTexture(GL_TEXTURE_2D, textureID);
	gluSphere(this->quad, radius, splices, stacks);
	glPopMatrix();
	glEnd();

}

