//
//  MainMenu.hpp
//  mountaineer
//
//  Created by Jackson Newlands on 2018-11-22.
//  Copyright © 2018 Jackson Newlands. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

#include "Button.hpp"


class MainMenu {
public:
    void displayMainMenu(); // displays the main menu
    void startButtonClicked();  // opens the gameworld

protected:
    void drawStartButton(); // draws the start button
    void drawTitle();   // draws the title of the main menu
};




#endif /* MainMenu_hpp */
