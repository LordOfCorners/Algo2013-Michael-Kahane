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
    void setup(float _gravity, float _damping, ofColor _color, ofVec2f _vel, ofVec2f pos, float _r);
    
    ofVec2f pos;
    ofVec2f vel;
    
    float r;
    ofColor ballColor;
    
    float gravity;
    float damping;


};