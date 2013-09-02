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
    
    void setup(ofPoint _pos, ofColor _color,float catchUpSpeed, int _width, int _height);
    void update(float _rate);
    void draw();
    
    void interpolateByPct(float myPct);
    
    void xenoToPoint(float catchX, float catchY);
    void displayInfo(ofPoint _infoPos);
    
    ofPoint pos;
    
    //for interpolation
    ofPoint posA, posB, infoPos;
    ofColor color;
    
    bool acrossScreen;
    float acrossScreenTime;
    float catchUpSpeed;
    
    int width,height;
    
    float rate;
};