//
//  Character.cpp
//  mountaineer
//
//  Created by Jackson Newlands on 2018-11-29.
//  Copyright © 2018 Jackson Newlands. All rights reserved.
//

#include "Character.hpp"


//House object constructor
Character::Character() {
    head =  Cube();
    body = Cube();
    rightArm = Cube();
    leftArm = Cube();
    leftLeg = Cube();
    rightLeg = Cube();

    
    head.translate(0.0, 1.5, 0.0);
    head.scaleChange(-0.5);
    
    body.scaleChange(-0.2);
    
    rightArm.scaleChange(-0.7);
    rightArm.translate(1.5, 0.2, 0.0);
    
    leftArm.scaleChange(-0.7);
    leftArm.translate(-1.5, 0.2, 0.0);
    
    rightLeg.scaleChange(-0.7);
    rightLeg.translate(0.8, -1.2, 0.0);
    
    leftLeg.scaleChange(-0.7);
    leftLeg.translate(-0.8, -1.2, 0.0);
    
}



void Character::draw() {
    
    glPushMatrix();
    this->ctmMultiply();
    glScalef(s,s,s);
    head.draw();
    glPopMatrix();
    
    glPushMatrix();
    this->ctmMultiply();
    glScalef(s,s,s);
    body.draw();
    glPopMatrix();
    
    glPushMatrix();
    this->ctmMultiply();
    glScalef(s,s,s);
    rightArm.draw();
    glPopMatrix();
    
    glPushMatrix();
    this->ctmMultiply();
    glScalef(s,s,s);
    leftArm.draw();
    glPopMatrix();
    
    glPushMatrix();
    this->ctmMultiply();
    glScalef(s,s,s);
    rightLeg.draw();
    glPopMatrix();
    
    glPushMatrix();
    this->ctmMultiply();
    glScalef(s,s,s);
    leftLeg.draw();
    glPopMatrix();

    
}

