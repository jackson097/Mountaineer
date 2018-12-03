#include "Sphere.hpp"
Sphere::Sphere(float rad, float red,  float green, float blue, GLuint text, Image* image) {
	radius = rad;
	mode = MODE_WIRE;
	textureID = text;
	texture_image = image;
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

void Sphere::set_textureID(GLuint text){
	textureID = text;
}

void Sphere::draw() {

	glPushMatrix();
	this->ctmMultiply();
	//glColor3f(r, g, b);
	//glBindTexture(GL_TEXTURE_2D, textureID);
	if (textureID != 0){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureID);

		//Bottom
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(r, g, b);
		//glBegin(GL_QUADS);
//////////////////		glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image->width, texture_image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image->pixels);
		gluQuadricDrawStyle(this->quad, GLU_FILL);

		gluQuadricTexture(this->quad, GL_TRUE);

		gluQuadricNormals(this->quad, GLU_SMOOTH);
		/**glNormal3f(0.0, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-2.5f, -2.5f, 2.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(2.5f, -2.5f, 2.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2.5f, -2.5f, -2.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-2.5f, -2.5f, -2.5f);
		*/
	}
	else {
		glColor3f(r, g, b);
		glBindTexture(GL_TEXTURE_2D, textureID);
	}
	gluSphere(this->quad, radius, splices, stacks);
	glPopMatrix();
	glEnd();

}

