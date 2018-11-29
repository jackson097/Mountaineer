//
//  Character.hpp
//  mountaineer
//
//  Created by Jackson Newlands on 2018-11-29.
//  Copyright © 2018 Jackson Newlands. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Cube.hpp"


class Character: public Shape {
protected:
    Cube head, body, rightArm, leftArm, rightLeg, leftLeg;

public:
    Character();
    void draw();
};



#endif /* Character_hpp */
