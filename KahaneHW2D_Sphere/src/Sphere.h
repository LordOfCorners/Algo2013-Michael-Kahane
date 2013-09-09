//
//  Ball.h
//  vectors
//
//  Created by Michael Kahane on 9/6/13.
//
//

#pragma once
#include "ofMain.h"

class Sphere{
public:
    Sphere();
    
    void update();
    void draw();
    void setup(ofColor _color, ofVec3f _vel, ofVec3f pos, float _r);
    
    ofVec3f pos;
    ofVec3f vel;
    float r;
    ofColor ballColor;
};