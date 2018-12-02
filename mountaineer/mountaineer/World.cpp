/**
 * File: World.hpp
 */

#include "World.hpp"
extern GLint paused;


// THE OBJNUM IS INCLUDING THE CUBES THAT APPEAR TO BE 2D BECAUSE OF THE ANGLE IN THE PAUSE MENU, THATS WHY I
// HAVE IF STATEMENTS IN EVERY METHOD HERE


World::World() {

	objnum = 9; // number of object
	list[0] = (Shape*) malloc( sizeof(Shape*) * objnum);  // array to hold object pointers
	list[0] = new Character();
	list[0]->scaleChange(-0.6);

	list[1] = new Cube();
	list[1]->translate(-3,0,0);
	list[1]->scaleChange(-0.6);
	list[2] = new Cube();
	list[2]->translate(3,0,0);
	list[2]->scaleChange(-0.6);

	list[3] = new Sphere();
	list[3]->translate(-1.5, -7, -11);
	list[4] = new Sphere();
	list[4]->translate(-4, -12, -11);
	list[5] = new Sphere();
	list[5]->translate(1, -2, -11);

	list[7] = new Cube();   // Resume Button
	list[7]->translate(0.0,2.0,0.0);
	list[7]->scaleChange(-0.6);
	list[8] = new Cube();   // Restart Button
	list[8]->scaleChange(-0.6);
	list[9] = new Cube();   // Quit Button
	list[9]->translate(0.0,-2.0,0.0);
	list[9]->scaleChange(-0.6);

}

World::~World(){
    if(paused == 3) {
       	for (int i = 0; i<objnum; i++)
            delete list[i];
        
        free(list);
    }
    
    else if (paused == 2) {
        for (int i = 0; i<objnum-3; i++)        // (objNum - 3) because this one doesn't include pause buttons
            delete list[i];
        
        free(list);
    }

}

void World::draw() {
    if(paused == 3) {
        for (int i = 0; i<objnum; i++) {
            list[i]->draw();
        }
    }
    else if(paused == 2) {
        for (int i = 0; i<objnum-3; i++) {
            list[i]->draw();
        }
    }
    
    
    
}

void World::reset() {
    
    if(paused == 3) {
        for (int i = 0; i<objnum; i++)
            list[i]->reset();
    }
    
    else if(paused == 2) {
        for (int i = 0; i<objnum-3; i++)
            list[i]->reset();
    }
}

