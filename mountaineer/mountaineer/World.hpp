#ifndef CWORLD_HPP
#define CWORLD_HPP


#include <iostream>
#include <stdlib.h>
#include "Cube.hpp"
#include "Character.hpp"
#include "Button.hpp"
#include "Sphere.hpp"
#include "Mountain.hpp"

class World {
public:
	GLint objnum;
	Shape *list[]; // array of object pointers
	World();       // constructor
	~World();      // destructor
	void draw();   // draw all objects in the world
	void reset();  // reset to default
};

#endif
