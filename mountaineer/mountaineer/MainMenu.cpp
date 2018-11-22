

#include "MainMenu.hpp"



void MainMenu::displayMainMenu() {
    printf("Displaying Main Menu... \n");
    glClearColor(0.0, 0.0, 1.0, 1.0);
    drawTitle();
    drawStartButton();
    drawSettingsButton();
}



void MainMenu::drawTitle() {
    // Learn how to add text OR bitmap file here with logo and title
}


void MainMenu::drawStartButton() {
    // Text on button or bitmap "START"
}


void MainMenu::drawSettingsButton() {
    // bitmap of a settings gear
}

void MainMenu::startButtonClicked() {
    
}

void MainMenu::settingsButtonClicked() {
    
}
