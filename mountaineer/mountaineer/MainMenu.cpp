

#include "MainMenu.hpp"

extern GLint winWidth, winHeight;
extern Button startButton;



void MainMenu::displayMainMenu() {
    drawStartButton();
    glutPostRedisplay();
}




void MainMenu::drawStartButton() {
    glColor3f(1.0, 0.0, 0.0);
    startButton.setPoints((winWidth/6)*3.5, (winHeight/10)*8, (winWidth/6)*2.5, (winHeight/10)*9);
    startButton.draw();
    glutPostRedisplay();

    
}

