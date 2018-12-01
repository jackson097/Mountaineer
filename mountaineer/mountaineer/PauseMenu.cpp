//
//  PauseMenu.cpp
//  mountaineer
//
//  Created by Jackson Newlands on 2018-11-29.
//  Copyright © 2018 Jackson Newlands. All rights reserved.
//

#include "PauseMenu.hpp"

extern GLint winWidth, winHeight;
extern Button resumeButton;
extern Button quitButton;
extern Button restartButton;



void PauseMenu::display() {
    resumeButton.setPoints((winWidth/6)*3.5, (winHeight/10)*8, (winWidth/6)*2.5, (winHeight/10)*9);
    quitButton.setPoints((winWidth/6)*3.5, ((winHeight/10)*8)-460, (winWidth/6)*2.5, ((winHeight/10)*9)-460);
    restartButton.setPoints((winWidth/6)*3.5, ((winHeight/10)*8)-220, (winWidth/6)*2.5, ((winHeight/10)*9)-220);
    
    resumeButton.draw();
    quitButton.draw();
    restartButton.draw();
    
    glutPostRedisplay();
}

