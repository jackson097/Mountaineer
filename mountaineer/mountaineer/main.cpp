
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

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
#include "PauseMenu.hpp"





// Global Variables
GLint winWidth = 800;
GLint winHeight = 700;
GLint worldOption = 1;
GLint displayGameWorld;
MainMenu menu;  // Main menu object
Button startButton;
Button resumeButton;
Button quitButton;
Button restartButton;
Camera myCamera;
World myWorld;
//PauseMenu pauseMenu;

GLint upPressed = 2;
GLint downPressed = 2;
GLint leftPressed = 2;
GLint rightPressed = 2;

Shape *sshapep = myWorld.list[0];
float timeFactor = 1;





void MyKeyboardFunc(unsigned char Key, int x, int y){
	GLfloat rx, ry, rz;
	if(Key == 'a'){
        leftPressed = 100;

	}if(Key == 'd'){
        rightPressed = 100;

    }else if(Key == 'w'){
        upPressed = 100;
        
    }else if(Key == 's'){
        downPressed = 100;
        
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


void MyKeyboardUpFunc(unsigned char key, int x, int y) {
    if(key == 'a'){
        leftPressed = 2;
        
    }if(key == 'd'){
        rightPressed = 2;
        
    }else if(key == 'w'){
        upPressed = 2;
        
    }else if(key == 's'){
        downPressed = 2;
    }
}



void MyArrowFunc(int Key, int x, int y) {
    
    if(Key == GLUT_KEY_LEFT){
        leftPressed = 100;
        
    }else if(Key == GLUT_KEY_RIGHT){
        rightPressed = 100;
        
    }else if(Key == GLUT_KEY_UP){
        upPressed = 100;
        
    }else if(Key == GLUT_KEY_DOWN){
        downPressed = 100;
    }
}



void SpecialKeysUp(int key, int x, int y) {
    
    if(key == GLUT_KEY_LEFT){
        leftPressed = 2;
        
    }else if(key == GLUT_KEY_RIGHT){
        rightPressed = 2;
        
    }else if(key == GLUT_KEY_UP){
        upPressed = 2;
        
    }else if(key == GLUT_KEY_DOWN){
        downPressed = 2;
    }
}


void Update() {

    if (upPressed == 100) {
        sshapep->translate(0.0, 0.002, 0.0);
    }
    if(downPressed == 100) {
        sshapep->translate(0.0, -0.002, 0.0);
    }
    if(leftPressed == 100) {
         sshapep->translate(-0.002,0.0,0.0);
    }
    if(rightPressed == 100){
        sshapep->translate(0.002, 0, 0);
    }
}

void physics(void){
	int i = 1;
	int j = 3;
	 // temporary for the speed up w.r.t time
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
		printf("p:(%.1f, %.1f) ", x, y);
		printf("o1: (%.1f, %.1f) ", x1, y1);
		printf("o2: (%.1f, %.1f)\n", x2, y2);
		if(myWorld.list[i]->outOfBounds()){
			myWorld.list[i]->randomX();
			myWorld.list[i]->translate(0,15,0);
			myWorld.list[i]->randomY();
		}
		if(c == 1){
			myWorld.list[i]->translate(0,5, 0);
		}
		myWorld.list[i]->translate(0, -0.0004 *timeFactor, 0);
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
    //Backface Test
    glEnable(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    // Camera setup
	myCamera.setDefaultCamera();
	myWorld.list[0]->translate(0,-2,0);
    glutPostRedisplay();

    
}





void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // World Options
    if(worldOption == 1) {   // Main Menu World
        menu.displayMainMenu();
        glFlush();
        glutSwapBuffers();
    }
    
    if(worldOption == 2) {  // Game World
        glClearColor(0.4, 1.0, 1.0, 0.0);
		myCamera.setProjectionMatrix();
		myWorld.draw();
		physics();
		timeFactor = timeFactor + 0.0001;
		printf("%.6f\n", timeFactor);


        glFlush();
        glutSwapBuffers();
    }
    
//   if(worldOption == 3) { // Pause Game
//        glClearColor(0.0, 0.0, 0.0, 0.0);
//        pauseMenu.display();
//       
//       glFlush();
//       glutSwapBuffers();
//    }
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
        printf("Clicked at %d, %d\n", x, y);
        if(worldOption == 1 && x < startButton.x1 && x > startButton.x2 && y > 554 && y < 621) {  // Start Button clicked
            menu.startButtonClicked();
            displayGameWorld = 1;
        }
    }
    
    if(button == GLUT_LEFT_BUTTON && action == GLUT_UP) {
        if (displayGameWorld == 1) {
            worldOption = 2;    // Start game
        }
    }
    glutPostRedisplay();
}







int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutReshapeFunc(winReshapeFcn);
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseAction);
    glutKeyboardFunc(MyKeyboardFunc);
    glutSpecialFunc(MyArrowFunc);
    glutSpecialUpFunc(SpecialKeysUp);
    glutKeyboardUpFunc(MyKeyboardUpFunc);
    glutIdleFunc(Update);
    glutMainLoop();
    return 0;
}

