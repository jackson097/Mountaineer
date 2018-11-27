/**
 * File: World.hpp
 */

#include "World.hpp"

World::World() {
	objnum = 1; // number of object
	list[0] = (Shape*) malloc( sizeof(Shape*) * objnum);  // array to hold object pointers
	list[0] = new Cube();
	list[0]->scaleChange(-0.3);

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

