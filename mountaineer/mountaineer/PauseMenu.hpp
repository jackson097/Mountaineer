//
//  PauseMenu.hpp
//  mountaineer
//
//  Created by Jackson Newlands on 2018-11-29.
//  Copyright © 2018 Jackson Newlands. All rights reserved.
//

#ifndef PauseMenu_hpp
#define PauseMenu_hpp



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


class PauseMenu {
public:
    void display();
};




#endif /* PauseMenu_hpp */
