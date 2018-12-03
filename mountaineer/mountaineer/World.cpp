/**
 * File: World.hpp
 */

#include "World.hpp"
extern GLint paused;
//extern GLuint textureID;
GLuint textureID = 0;
Image *image;

// THE OBJNUM IS INCLUDING THE CUBES THAT APPEAR TO BE 2D BECAUSE OF THE ANGLE IN THE PAUSE MENU, THATS WHY I
// HAVE IF STATEMENTS IN EVERY METHOD HERE


World::World() {

	objnum = 9; // number of object

	image = loadBMP("moon.bmp");
	textureID = loadTexture(image);
    
	list[0] = (Shape*) malloc( sizeof(Shape*) * objnum);  // array to hold object pointers
	list[0] = new Character();
	list[0]->scaleChange(-0.6);

	list[1] = new Sphere(0.5, 0.8, 0.8, 0.8, textureID, image);
	list[1]->translate(-3,0,0);
	list[1]->scaleChange(-0.6);
    
	list[2] = new Sphere(0.5, 0.8, 0.8, 0.8, textureID, image);
	list[2]->translate(3,0,0);
	list[2]->scaleChange(-0.6);
    
    // Mountain
	list[3] = new Sphere(10, 0.5, 0.5, 0.5, textureID, image);
	list[3]->translate(-1.5, -7, -11);
    
	list[4] = new Sphere(10, 0.5, 0.5, 0.5, textureID, image);
	list[4]->translate(-4, -12, -11);
    
	list[5] = new Sphere(10, 0.5, 0.5, 0.5, textureID, image);
	list[5]->translate(1, -2, -11);
    
    
    // Pause Menu Stuff
	list[6] = new Cube();   // Resume Button
	list[6]->translate(0.0,2.0,0.0);
	list[6]->scaleChange(-0.6);
    
	list[7] = new Cube();   // Restart Button
	list[7]->scaleChange(-0.6);
    
	list[8] = new Cube();   // Quit Button
	list[8]->translate(0.0,-2.0,0.0);
	list[8]->scaleChange(-0.6);

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

//Makes the image into a texture, and returns the id of the texture
GLuint World::loadTexture(Image* image) {
	GLuint text;
	glGenTextures(1, &text); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, text); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return text; //Returns the id of the texture
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

