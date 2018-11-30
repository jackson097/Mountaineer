//
//  Button.cpp
//  mountaineer
//
//  Created by Jackson Newlands on 2018-11-26.
//  Copyright © 2018 Jackson Newlands. All rights reserved.
//

#include "Button.hpp"



Button::Button(){
	this->x1 = 0;
	this->x2 = 0;
	this->y1 = 0;
	this->y2 = 0;

}


void Button::setPoints(GLint x1, GLint y1, GLint x2, GLint y2) {
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}


void Button::draw() {
    glBegin(GL_POLYGON);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();

}





