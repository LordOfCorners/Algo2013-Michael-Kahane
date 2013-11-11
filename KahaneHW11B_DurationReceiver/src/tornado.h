//
//  tornado.h
//  KahaneHW3C_phenomenon
//
//  Created by Michael Kahane on 9/17/13.
//
//

#pragma once
#include "ofMain.h"

class Tornado {
public:
    Tornado();
    
    void setup(float _timer);
    void update();
    void draw(float lineThickness);
    ofPoint pos;
    float y;
    ofColor color;
    float radius;
    vector <ofPoint> pointList;
    float timer;

};