/*
 * Mountain.hpp
 *
 *  Created on: Nov 29, 2018
 *      Author: Stefan
 */

#ifndef MOUNTAINEER_MOUNTAIN_HPP_
#define MOUNTAINEER_MOUNTAIN_HPP_

#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include "Sphere.hpp"

class Mountain: public Shape
{

public:
	Sphere sphere;
	Mountain();
	void draw();

};



#endif /* MOUNTAINEER_MOUNTAIN_HPP_ */
