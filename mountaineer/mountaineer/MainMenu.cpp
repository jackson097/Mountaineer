

#include "MainMenu.hpp"

extern GLint winWidth, winHeight;
extern Button startButton;



void MainMenu::displayMainMenu() {
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
    startButton.setPoints((winWidth/6)*3.5, (winHeight/10)*8, (winWidth/6)*2.5, (winHeight/10)*9);
    startButton.draw();
    
}


void MainMenu::drawSettingsButton() {
    // bitmap of a settings gear
}

void MainMenu::startButtonClicked() {
    printf("Start button clicked\n");
}

void MainMenu::settingsButtonClicked() {
    
}




