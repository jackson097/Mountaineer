/**
 * File: World.hpp
 */

#include "World.hpp"
extern GLint paused;


// THE OBJNUM IS INCLUDING THE CUBES THAT APPEAR TO BE 2D BECAUSE OF THE ANGLE IN THE PAUSE MENU, THATS WHY I
// HAVE IF STATEMENTS IN EVERY METHOD HERE


World::World() {

	objnum = 6; // number of object
	list[0] = (Shape*) malloc( sizeof(Shape*) * objnum);  // array to hold object pointers
	list[0] = new Character();
	list[0]->scaleChange(-0.6);
	list[1] = new Cube();
	list[1]->translate(-3,0,0);
	list[1]->scaleChange(-0.6);
	list[2] = new Cube();
	list[2]->translate(3,0,0);
	list[2]->scaleChange(-0.6);
    list[3] = new Cube();   // Resume Button
    list[3]->translate(0.0,2.0,0.0);
    list[3]->scaleChange(-0.6);
    list[4] = new Cube();   // Restart Button
    list[4]->scaleChange(-0.6);
    list[5] = new Cube();   // Quit Button
    list[5]->translate(0.0,-2.0,0.0);
    list[5]->scaleChange(-0.6);

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

