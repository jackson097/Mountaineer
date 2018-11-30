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

	sphere.draw();
}


