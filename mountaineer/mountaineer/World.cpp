/**
 * File: World.hpp
 */

#include "World.hpp"

World::World() {
	objnum = 1; // number of object
	list[0] = (Shape*) malloc( sizeof(Shape*) * objnum);  // array to hold object pointers
	list[0] = new Cube();
	list[0]->scaleChange(-0.3);
//
//	list[1] = new Pyramid();
//	list[1]->scaleChange(-0.2);
//	list[1]->translate(-2.5,0,0);
//
//	list[2] = new House();
//	//list[2]->scaleChange(-0.2);
//	list[2]->translate(2.5,0,0);

}

World::~World(){
	for (int i = 0; i<objnum; i++)
	   delete list[i];

	free(list);
}

void World::draw() {
	for (int i = 0; i<objnum; i++)
	   list[i]->draw();
}

void World::reset() {
	for (int i = 0; i<objnum; i++)
	   list[i]->reset();
}

