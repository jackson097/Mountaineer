#include "Sphere.hpp"

Sphere::Sphere() {
	radius = 10.0;
	mode = MODE_WIRE;
	textureID = 0;
	splices = 15;
	stacks = 15;
	quad = gluNewQuadric();
	r = 0.5;
	g = 0.5;
	b = 0.5;
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

