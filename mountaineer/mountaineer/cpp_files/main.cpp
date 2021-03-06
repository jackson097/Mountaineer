
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <Mmsystem.h>
//#include <mciapi.h>
#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include <iostream>
#include <fstream>
#include <sstream>
#include "../header_files/MainMenu.hpp"
#include "../header_files/Button.hpp"
#include "../header_files/Camera.hpp"
#include "../header_files/World.hpp"
#include "../header_files/Sphere.hpp"
#include "../header_files/Image.hpp"


// Global Variables
//Image* image;
//extern GLuint textureID;
//GLuint textureId = text; //The id of the texture

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
int health = 3;
// Used 2's and 100's instead of 0's and 1's because of error caused by using 0's and 1's
// 2 indicates OFF, 100 indicates ON
GLint leftPressed, rightPressed, paused, pauseFlag, resumeFlag, resetFlag, restartFlag, gameOverFlag = 2;
GLint BOULDER_MAX = 18

Shape *sshapep = myWorld.list[0];
float timeFactor = 1;
float speedFactor = 1;
float stupid = 1;
int MAX_BOULDERS = 5;

GLint boulderSpeedMultiple = 1;

#if __APPLE__
GLfloat translateConstant = 0.15;
GLfloat translateConstant2 = 0.04;
#else
GLfloat translateConstant = 0.040;
GLfloat translateConstant2 = 0.010;
#endif

void output(float x, float y, float z, float r, float g, float b, char *string) {
  glColor3f( r, g, b );
  glRasterPos3f(x, y, z);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
  }
}

void MyKeyboardFunc(unsigned char Key, int x, int y){
    if(worldOption == 2) {
        if(Key == 'a'){
            leftPressed = 100;
        } if(Key == 'd'){
            rightPressed = 100;
		// If escape is clicked
        } else if (health > 0 && Key == 27) {
            paused = 3;
        }
    }
}

void MyKeyboardUpFunc(unsigned char key, int x, int y) {
    if(worldOption == 2){
        if(key == 'a'){
            leftPressed = 2;
            
        }if(key == 'd'){
            rightPressed = 2;
        }
    }
}

void MyArrowFunc(int Key, int x, int y) {
    if(worldOption == 2){
        if(Key == GLUT_KEY_LEFT){
            leftPressed = 100;       
        }
		else if(Key == GLUT_KEY_RIGHT){
            rightPressed = 100;
        }
    }
}

void SpecialKeysUp(int key, int x, int y) {
    if(worldOption == 2) {
        if(key == GLUT_KEY_LEFT){
            leftPressed = 2;
            
        }else if(key == GLUT_KEY_RIGHT){
            rightPressed = 2;
        }
    }
}

void Update() {
    if(worldOption == 2) {
        if(leftPressed == 100) {
            sshapep->translate(-translateConstant,0.0,0.0);
        }
        if(rightPressed == 100){
            sshapep->translate(translateConstant, 0, 0);
        }
    }
}

void physics(void){

	GLfloat rx, ry, rz;
	int i = 1;
	int j = 3;
	myWorld.list[0]->stayInBound();
	if(timeFactor / 10 < 2){
		j = 3 + int(timeFactor /10);
	}else{
		j = 5;
	}
	for(; i < j; i++){
		//if(i != 3){
			int c = myWorld.list[0]->checkCollision(myWorld.list[i]);
			//Shape *temp = myWorld.list[0]; //must grab a temp pointer or else getters wont work
//			GLfloat x = temp->getX();
//			GLfloat y = temp->getY();
//			temp = myWorld.list[1];
//			GLfloat x1 = temp->getX();
//			GLfloat y1 = temp->getY();
//			temp = myWorld.list[2];
//			GLfloat x2 = temp->getX();
//			GLfloat y2 = temp->getY();
			//printf("p:(%.1f, %.1f) ", x, y);
			//printf("o1: (%.1f, %.1f) ", x1, y1);
			//printf("o2: (%.1f, %.1f)\n", x2, y2);
//
			if(myWorld.list[i]->outOfBounds()){
				myWorld.list[i]->randomX();
				myWorld.list[i]->translate(0,15,0);
				myWorld.list[i]->randomY();
			}
			if(c == 1 && stupid >= timeFactor *100){
				char oof[3] = {'O','O','F'};
				output(0,0,0,1,1,1,oof);
				myWorld.list[i]->translate(0,12, 0);
				health -=1;
				//PlaySound((LPCSTR) "music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			}
			if(timeFactor < BOULDER_MAX){
				speedFactor = timeFactor;
			}else{
				speedFactor = BOULDER_MAX;
			}

			// Make boulders all different speeds
			if(i == 1) {
				boulderSpeedMultiple = 1.0;
			} else if (i == 2) {
				boulderSpeedMultiple = 1.7;
			} else if (i == 3) {
				boulderSpeedMultiple = 1.2;
			} else if (i == 4) {
				boulderSpeedMultiple = 1.4;
			}

			 myWorld.list[i]->translate(0, -translateConstant2 * speedFactor * boulderSpeedMultiple, 0);
			rx = myWorld.list[5]->getMC().mat[0][0];
			ry = myWorld.list[5]->getMC().mat[1][0];
			rz = myWorld.list[5]->getMC().mat[2][0];
			myWorld.list[5]->rotateMC(rx, ry, rz, 0.02);
			rx = myWorld.list[6]->getMC().mat[0][0];
			ry = myWorld.list[6]->getMC().mat[1][0];
			rz = myWorld.list[6]->getMC().mat[2][0];
			myWorld.list[6]->rotateMC(rx, ry, rz, 0.02);
			rx = myWorld.list[7]->getMC().mat[0][0];
			ry = myWorld.list[7]->getMC().mat[1][0];
			rz = myWorld.list[7]->getMC().mat[2][0];
			myWorld.list[7]->rotateMC(rx, ry, rz, 0.02);
		}
	//}
}

void pauseGame() {
    glutIdleFunc(NULL);
    
    // Words on pause buttons
    char resume[100] = {'R','E','S','U','M', 'E'};
    output(-0.33,1.8,1, 1,1,1, resume);
    
    char reset[100] = {'R','E','S','E','T'};
    output(-0.26,-0.1,1, 1,1,1, reset);
    
    char quit[100] = {'Q','U','I','T'};
    output(-0.199,-1.92,1, 1,1,1, quit);
    
    
    if(pauseFlag == 2) {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        
        myCamera.eye.set(0, 0, 11);
        myCamera.setProjectionMatrix();
        
        for(int i = 0; i < 8; i++) {
            myWorld.list[i]->translate(20.0,-20.0,0.0);
        }

        resetFlag = 2;
        pauseFlag = 3;
        
    }
}






void restartGame() {
	PlaySound((LPCSTR) "music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    if(resetFlag == 2) {

		paused = 2; // unpause
		pauseFlag = 2;
		timeFactor = 1;
		resetFlag = 3;
		health = 3;
		gameOverFlag = 2;

		if(restartFlag == 2) {  // If not on gameOver menu
			// Move characters and cubes back
			for(int i = 0; i < 8; i++) {
				myWorld.list[i]->translate(-20.0,20.0,0.0);
			}
		}

		else{
			restartFlag = 2;
		}

		// Move character to origin
		GLint x = myWorld.list[0]->getX();
		GLint y = myWorld.list[0]->getY();
		myWorld.list[0]->translate(-x, -y - 2, 0);


		// Move boulders up to top
		myWorld.list[1]->translate(0.0,10.0,0.0);
		myWorld.list[2]->translate(0.0,9.0,0.0);
		myWorld.list[3]->translate(0.0,11.0,0.0);
		myWorld.list[4]->translate(0.0,10.2,0.0);

		//reset score
		//stupid = 1;

		/*
		 // Move boulders up to top if they're on screen
		 GLint list1Y = myWorld.list[1]->getY();
		 GLint list2Y = myWorld.list[3]->getY();
		 GLint list3Y = myWorld.list[3]->getY();
		 GLint list4Y = myWorld.list[4]->getY();


		 if(list1Y < 5) {
		 myWorld.list[1]->translate(0.0,10.0,0.0);
		 }
		 if(list2Y < 5) {
		 myWorld.list[2]->translate(0.0,10.0,0.0);
		 }
		 if(list3Y < 5) {
		 myWorld.list[3]->translate(0.0,9.0,0.0);
		 }
		 if(list4Y < 5) {
		 myWorld.list[4]->translate(0.0,10.5,0.0);
		 }
		 */
	}
}

void resumeGame() {
    if(resumeFlag == 3) {
        // Move characters and cubes back
        for(int i = 0; i < 8; i++) {
            myWorld.list[i]->translate(-20.0,20.0,0.0);
        }
        resumeFlag = 2;
        paused = 2; // unpause
        pauseFlag = 2;
        resetFlag = 3;
    }
    
    glClearColor(0.4, 1.0, 1.0, 0.0);
    myCamera.eye.set(5, 5, 10);
    myCamera.setProjectionMatrix();
    glutIdleFunc(Update);
    physics();
    timeFactor = timeFactor + 0.0005;
    //printf("%.6f\n", timeFactor);
}

void quitGame() {
    exit(0);
}

void init(void) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(250, 0);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Mountaineer");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, winWidth, winHeight, 0.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    PlaySound((LPCSTR) "music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    //Backface Test
    glEnable(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    // Camera setup
	myCamera.setDefaultCamera();
	myWorld.list[0]->translate(0,-2,0);
    glutPostRedisplay();
}

void deathAnimation(int n){
    while(myWorld.list[0]->getY() > -1){
        printf("a\n");
        float rx = myWorld.list[0]->getMC().mat[0][2];
        float ry = myWorld.list[0]->getMC().mat[1][2];
        float rz = myWorld.list[0]->getMC().mat[2][2];
        sshapep = myWorld.list[0];
        sshapep->rotateMC(rx,ry,rz, 0.5);
        float higherPos = myWorld.list[0]->getY();
        float lowerPos = myWorld.list[0]->getY() -0.05;
        while(higherPos > lowerPos){
            printf("b\n");
            myWorld.list[0]->translate(0, -translateConstant, 0);
            higherPos -= translateConstant/8;
            //myWorld.draw();

            //glFlush();
            //glutSwapBuffers();
            //glutPostRedisplay();
        }
        myWorld.draw();
        glutPostRedisplay();
        glutTimerFunc(20,deathAnimation,n);
        //printf("got here\n");
        //glFlush();
        glutSwapBuffers();
        //glutPostRedisplay();

    }
}

void gameOver(){
	gameOverFlag = 3;
	resetFlag = 2;
	//PlaySound((LPCSTR) "death_sound.wav", NULL, SND_FILENAME | SND_ASYNC );
	// Strings to display on screen for game over screen
	glClearColor(0.0, 0.0, 0.0, 0.0);
	char gameOver[100] = {'G','A','M','E', ' ', ' ','O','V','E','R'};
	output(-0.2,2,1, 1, 0, 0, gameOver);

	char reset[100] = {'R','E','S','E','T'};
	output(-0.05,-0.1,1, 1,1,1, reset);

	char quit[100] = {'Q','U','I','T'};
	output(0,-1.92,1, 1,1,1, quit);


	glutPostRedisplay();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // World Options
    if(worldOption == 1) {   // Main Menu World
        
        char start[100] = {'S','T','A','R','T'};
        output(370,600,1, 1,1,1, start);

        menu.displayMainMenu();
        glFlush();
        glutSwapBuffers();
    }
    
    if(worldOption == 2) {      // Game World

        if(paused == 3) {
            pauseGame();
            
        }else {
            resumeGame();
        }
        if(health > 0){
            char score[100] = {'S','C','O','R','E', ':'};
            char scoreBuffer[10];
            itoa(int(timeFactor* 100), scoreBuffer, 10);
            char highScore[100] = {'H','I','G','H','S','C','O','R','E', ':'};
            char highScoreBuffer[10];

            if(stupid < timeFactor *100){
                stupid = timeFactor *100;
            }
            itoa(int(stupid), highScoreBuffer, 10);
            output(-4,3.9, 1,0,0,0, score);
            output(-2,3.99, 1,0,0,0, scoreBuffer);

            output(-4.03,3.7, 1,0,0,0, highScore);
            output(-2.03,3.79, 1,0,0,0, highScoreBuffer);

            //LIVESSSSSS
            char lives[100] = {'L','I','V','E','S',':'};
            char livesBuffer[100];
            itoa(health, livesBuffer, 10);
            output(-4,3.5, 1,0,0,0, lives);
            output(-2,3.59, 1,0,0,0, livesBuffer);

            myWorld.draw();

        }else{
            //death animation and outro to game over screen
            //deathAnimation(60*3); //DEATH ANIMATION IS TOO HARD
            gameOver();
        }
        
        
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
        //  printf("Clicked at %d, %d\n", x, y);
        if(worldOption == 1 && x < startButton.x1 && x > startButton.x2 && y > 554 && y < 621) {  // Start Button clicked
            displayGameWorld = 1;
        }
    }
    // Determine where the screen was clicked. If it clicked a certain box on the screen, react accordingly
    if(button == GLUT_LEFT_BUTTON && action == GLUT_UP) {
        // Start game from main menu
        if (displayGameWorld == 1) {
            worldOption = 2;
        }
        // Pause Menu
        if(paused == 3) {
            if(x > 360 && x < 440 && y > 310 && y < 385) {
                restartGame();
            }
            if(x > 360 && x < 440 && y > 133 && y < 205) {
                resumeFlag = 3;
                resumeGame();
            }
            
            if(x > 360 && x < 441 && y > 490 && y < 560) {
                quitGame();
            }
        }
        // Game Over Menu
        if(gameOverFlag == 3) {
            restartFlag = 3;
            if(x > 355 && x < 410 && y > 368 && y < 384) {
            	//PlaySound((LPCSTR) "music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                restartGame();
            }

            else if(x>361 && x<405 && y>496 && y<510) {
                quitGame();
            }
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
    glutMainLoop();
    return 0;
}
