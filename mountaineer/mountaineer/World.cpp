/**
 * File: World.hpp
 */

#include "World.hpp"
extern GLint paused;
extern GLint objNum;


World::World() {

	objnum = 11; // number of object
    
	list[0] = (Shape*) malloc( sizeof(Shape*) * objnum);  // array to hold object pointers
    
    // Character
	list[0] = new Character();
	list[0]->scaleChange(-0.6);

    // Boulders
	list[1] = new Sphere(0.5,0.8,0.8,0.8);
	list[1]->translate(-3,10,0);
	list[1]->scaleChange(-0.6);
    
	list[2] = new Sphere(0.5,0.8,0.8,0.8);
	list[2]->translate(3,10,0);
	list[2]->scaleChange(-0.6);

	list[3] = new Sphere(0.5,0.8,0.8,0.8);
	list[3]->translate(3,15,0);
	list[3]->scaleChange(-0.6);

	list[4] = new Sphere(0.5,0.8,0.8,0.8);
	list[4]->translate(-3,15,0);
	list[4]->scaleChange(-0.6);

    // Mountain
	list[5] = new Sphere(10,0.5,0.5,0.5);
	list[5]->translate(-1.5, -7, -11);
    
	list[6] = new Sphere(10,0.5,0.5, 0.5);
	list[6]->translate(-4, -12, -11);
    
	list[7] = new Sphere(10,0.5,0.5,0.5);
	list[7]->translate(1, -2, -11);
    
    
    // Pause Menu Buttons
	list[8] = new Cube();   // Resume Button
	list[8]->translate(0.0,2.0,0.0);
	list[8]->scaleChange(-0.6);
    
	list[9] = new Cube();   // Restart Button
	list[9]->scaleChange(-0.6);
    
	list[10] = new Cube();   // Quit Button
	list[10]->translate(0.0,-2.0,0.0);
	list[10]->scaleChange(-0.6);


}

World::~World(){
    if(paused == 3) {
       	for (int i=0; i<objnum; i++)
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

