
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
#include "Button.hpp"
#include "Camera.hpp"
#include "World.hpp"
#include "Shape.hpp"



// Global Variables
GLint winWidth = 800;
GLint winHeight = 700;
GLint worldOption = 1;
GLint displayGameWorld;
MainMenu menu;  // Main menu object
Button startButton;
Camera myCamera;
World myWorld;
extern int objnum;




void MyKeyboardFunc(unsigned char Key, int x, int y){
	Shape *sshapep = myWorld.list[0];
	GLfloat rx, ry, rz;
	if(Key == 'a'){
		sshapep->translate(-0.05,0.0,0.0);

	}else if(Key == 'd'){
		sshapep->translate(0.05, 0, 0);

    }else if(Key == 'w'){
        sshapep->translate(0.0, 0.05, 0.0);
        
    }else if(Key == 's'){
        sshapep->translate(0.0, -0.05, 0.0);
        
    }else if(Key == 'q'){
		rx = sshapep->getMC().mat[0][0];
		ry = sshapep->getMC().mat[1][0];
		rz = sshapep->getMC().mat[2][0];
		sshapep->rotateMC(rx, ry, rz, -2);
	}else if(Key == 'e'){
		rx = sshapep->getMC().mat[0][0];
		ry = sshapep->getMC().mat[1][0];
		rz = sshapep->getMC().mat[2][0];
		sshapep->rotateMC(rx, ry, rz, 2);
	}
}



void MyArrowFunc(int Key, int x, int y){
    Shape *sshapep = myWorld.list[0];
    if(Key == GLUT_KEY_LEFT){
        sshapep->translate(-0.05,0.0,0.0);
        
    }else if(Key == GLUT_KEY_RIGHT){
        sshapep->translate(0.05, 0, 0);
        
    }else if(Key == GLUT_KEY_UP){
        sshapep->translate(0.0, 0.05, 0.0);
        
    }else if(Key == GLUT_KEY_DOWN){
        sshapep->translate(0.0, -0.05, 0.0);
    }
}




void init(void) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 400);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Mountaineer");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, winWidth, winHeight, 0.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);

	myCamera.setDefaultCamera();       // initialize camera
	myWorld.list[0]->translate(0,-2,0);
    glutPostRedisplay();

    
}

void physics(void){
	int i = 1;
	int j = 3;
	int timeFactor = 1; // temporary for the speed up w.r.t time
	for(; i < j; i++){

		int c = myWorld.list[0]->checkCollision(myWorld.list[i]);
		Shape *temp = myWorld.list[0]; //must grab a temp pointer or else getters wont work
		GLfloat x = temp->getX();
		GLfloat y = temp->getY();
		temp = myWorld.list[1];
		GLfloat x1 = temp->getX();
		GLfloat y1 = temp->getY();
		temp = myWorld.list[2];
		GLfloat x2 = temp->getX();
		GLfloat y2 = temp->getY();
		printf("p:(%.1f, %.1f)", x, y);
		printf("o1: (%.1f, %.1f)", x1, y1);
		printf("o2: (%.1f, %.1f)\n", x2, y2);

		if(c == 1){
			myWorld.list[i]->translate(0,15, 0);
		}
		myWorld.list[i]->translate(0, -0.0002 *timeFactor, 0);
	}

}



void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //printf("WORLD OPTION = %d\n", worldOption);
    
    // World Options
    if(worldOption == 1) {   // Main Menu World
        menu.displayMainMenu();
        glFlush();
        glutSwapBuffers();
    }
    
    if(worldOption == 2) {  // Game World
        glClearColor(0.0, 1.0, 1.0, 0.0);
		myCamera.setProjectionMatrix();
		physics();

		myWorld.draw();

        glFlush();
        glutSwapBuffers();
    }
    glutPostRedisplay();

}





void winReshapeFcn(GLint newWidth, GLint newHeight) {
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    winWidth = newWidth;
    winHeight = newHeight;
}





void mouseAction(int button, int action, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
        //printf("Clicked at %d, %d\n", x, y);
        if(worldOption == 1 && x < startButton.x1 && x > startButton.x2 && y > 554 && y < 621) {  // Start Button clicked
            menu.startButtonClicked();
            displayGameWorld = 1;
        }
    }
    
    if(button == GLUT_LEFT_BUTTON && action == GLUT_UP && displayGameWorld == 1) {
        worldOption = 2;    // Start game

    }
    glutPostRedisplay();
}







int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutReshapeFunc(winReshapeFcn);
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseAction);
    glutSpecialFunc(MyArrowFunc);
    glutKeyboardFunc(MyKeyboardFunc);
    glutMainLoop();
    return 0;
}

