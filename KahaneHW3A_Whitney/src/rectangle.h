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
    
    void setup(ofVec2f _pos, ofVec2f _newPos, ofColor _color, int _width, int _height, ofVec2f _newPos2, ofVec2f _newPos3);
    void update();
    void draw();
    void interpolateByPct(ofVec2f _posA, ofVec2f _posB, float myPct);
    
    ofVec2f pos,newPos,newPos2,newPos3;
    ofColor color;
    int width,height;
    ofVec2f posA,posB;
    float rate,pct;
};