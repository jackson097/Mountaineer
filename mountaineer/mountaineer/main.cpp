
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include "MainMenu.hpp"
#include "GameWorld.hpp"





// Global Variables
GLint winWidth = 1000;
GLint winHeight = 900;
GLint worldOption = 1;
MainMenu menu;  // Main menu object
GameWorld gameWorld; // GameWorld object





void init(void) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 400);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Mountaineer");
    glClearColor(1.0, 1.0, 1.0, 1.0);  //Set display-window color to black
    
}





void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    printf("WORLD OPTION = %d\n", worldOption);
    
    // World Options
    if(worldOption == 1) {   // Main Menu World
        menu.displayMainMenu();
        glutSwapBuffers();
    }
    
    if(worldOption == 2) {  // Game World
        gameWorld.displayGameWorld();
        glutSwapBuffers();
    }
}







int main(int argc, char** argv) {
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

