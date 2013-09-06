//
//  rectangle.h
//  Rectangles
//
//  Created by Michael Kahane on 8/27/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void setup(ofVec2f _pos, ofColor _color,float catchUpSpeed, int _width, int _height);
    void update(float _rate);
    void draw();
    
    void interpolateByPct(float myPct);
    
    void xenoToPoint(ofVec2f _catchMouse);
    void displayInfo(ofVec2f _infoPos);
    
    ofVec2f pos;
    
    //for interpolation
    ofVec2f posA, posB, infoPos;
    ofColor color;
    
    bool acrossScreen;
    float acrossScreenTime;
    float catchUpSpeed;
    
    int width,height;
    
    float rate;
};