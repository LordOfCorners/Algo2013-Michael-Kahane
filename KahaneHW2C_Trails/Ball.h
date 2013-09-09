//
//  Ball.h
//  vectors
//
//  Created by Michael Kahane on 9/6/13.
//
//

#pragma once
#include "ofMain.h"

class Ball{
public:
    Ball();
    
    void update();
    void draw();
    
    ofVec2f pos;
    float xVelocity;
    float yVelocity;
    float r = ofRandom(1,2);
    ofColor ballColor;
};