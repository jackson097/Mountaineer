

#include "MainMenu.hpp"

extern GLint winWidth, winHeight;




/*// ==============================================================================
 
 TO DO FOR JACKSON:
    - Figure out window reshape function
    - Click on start button and highlight it (Get the right coordinates)

*/// ==============================================================================





void MainMenu::displayMainMenu() {
    glClearColor(0.0, 0.8, 1.0, 1.0);
    drawTitle();
    drawStartButton();
    drawSettingsButton();
    printf("Displaying Main Menu... \n");
}



void MainMenu::drawTitle() {
    // Learn how to add text OR bitmap file here with logo and title
}


void MainMenu::drawStartButton() {
    printf("Drawing start button...\n");
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f((winWidth/3)*2, (winHeight/10)*8);
        glVertex2f(winWidth/3, (winHeight/10)*8);
        glVertex2f(winWidth/3, (winHeight/10)*9);
        glVertex2f((winWidth/3)*2, (winHeight/10)*9);
    glEnd();
}


void MainMenu::drawSettingsButton() {
    // bitmap of a settings gear
}

void MainMenu::startButtonClicked() {
    printf("Start button clicked\n");
}

void MainMenu::settingsButtonClicked() {
    
}




