/**
 * File: World.hpp
 */

#include "World.hpp"

World::World() {
	objnum = 3; // number of object
	list[0] = (Shape*) malloc( sizeof(Shape*) * objnum);  // array to hold object pointers
	list[0] = new Character();
	list[0]->scaleChange(-0.6);
	list[1] = new Cube();
	list[1]->translate(-3,0,0);
	list[1]->scaleChange(-0.6);
	list[2] = new Cube();
	list[2]->translate(3,0,0);
	list[2]->scaleChange(-0.6);

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

