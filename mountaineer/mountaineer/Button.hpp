//
//  Button.hpp
//  mountaineer
//
//  Created by Jackson Newlands on 2018-11-26.
//  Copyright © 2018 Jackson Newlands. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>


class Button {
    
    public:
        Button();
        GLint x1, x2, y1, y2;
        void draw();
        void setPoints(GLint x1, GLint y1, GLint x2, GLint y2);
};



#endif /* Button_hpp */
