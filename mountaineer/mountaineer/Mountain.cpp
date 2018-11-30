/*
 * Mountain.cpp
 *
 *  Created on: Nov 29, 2018
 *      Author: Stefan
 */

#include "Mountain.hpp"
#include <stdio.h>

Mountain::Mountain()
{
	sphere = Sphere();
}


void Mountain::draw()
{

	sphere.set_colour(0.5, 0.5, 0.5);
	sphere.set_radius(10.0);
	sphere.draw();
}


